MODULE_NAME = dbr-gpio-driver
obj-m += $(MODULE_NAME).o

KDIR = /lib/modules/$(shell uname -r)/build
PI_DIR = ~/gpio-driver
PI_HOST = pi@raspberrypi

all: dbr-gpio-driver.ko

$(MODULE_NAME).ko:
	make -C $(KDIR) M=$(shell pwd) modules

install: $(MODULE_NAME).ko
	rmmod $(MODULE_NAME); \
	insmod $(MODULE_NAME).ko

clean:
	make -C $(KDIR) M=$(shell pwd) clean; \
	rmmod $(MODULE_NAME)

deploy:
	ssh $(PI_HOST) "rm -r $(PI_DIR); mkdir $(PI_DIR)"; \
	scp * $(PI_HOST):$(PI_DIR)
