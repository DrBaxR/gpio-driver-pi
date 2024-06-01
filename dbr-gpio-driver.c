#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

#include <linux/proc_fs.h>
#include <linux/slab.h>

#define DBR_MAX_USER_SIZE 1024

static struct proc_dir_entry *dbr_proc = NULL;
static char data_buffer[DBR_MAX_USER_SIZE];

ssize_t dbr_read(struct file *file, char __user *user, size_t size, loff_t *off) {
  copy_to_user(user, "Data from kernel...\n", 20);
  return 20;
}

ssize_t dbr_write(struct file *file, const char __user *user, size_t size, loff_t *off) {
  memset(data_buffer, 0x0, sizeof(data_buffer));

  if (size > DBR_MAX_USER_SIZE) {
    size = DBR_MAX_USER_SIZE;
  }

  copy_from_user(data_buffer, user, size);

  printk("GPIO: Received '%s'\n", data_buffer);
  return size;
}

static const struct proc_ops dbr_proc_fops = 
{
	.proc_read = dbr_read,
	.proc_write = dbr_write,
};

static int __init gpio_driver_init(void) {
  printk("GPIO: Initializing driver...\n");

  dbr_proc = proc_create("dbr-gpio", 0666, NULL, &dbr_proc_fops);
  if (dbr_proc == NULL) {
    return -1;
  }

  return 0;
}

static void __exit gpio_driver_exit(void) {
  printk("GPIO: Exiting driver...");
  proc_remove(dbr_proc);
  return;
}

module_init(gpio_driver_init);
module_exit(gpio_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DrBaxR");
MODULE_DESCRIPTION("Sample GPIO driver for Raspberry Pi");
MODULE_VERSION("1.0");
