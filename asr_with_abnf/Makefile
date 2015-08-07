#common makefile header

export BASEDIR=$(PWD)/../../prj
include $(BASEDIR)/scripts/configure.mk

MODULE_EXEC	= asrdemo_with_abnf
MODULE_TARGET	= $(MODULE_EXEC)
LOCAL_INCLUDE	= -I$(BASEDIR)/../include
LOCAL_FLAGS	= $(LOCAL_INCLUDE) $(PIC_FLAG)
LIBS	:= -L$(BASEDIR-BIN) -lmsc -ldl -lpthread -lrt

MODULE_OBJ   = \
	$(MODULE_OUTPUT)/asrdemo_with_abnf.o

#common makefile foot
include $(BASEDIR)/scripts/rules.mk
