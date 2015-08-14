#common makefile header

#export BASEDIR=$(PWD)/../../prj
export BASEDIR=$(PWD)/prj
include $(BASEDIR)/scripts/configure.mk
export LD_LIBRARY_PATH=/home/turtlebot2/asr_ws/src/asr_userword/include/asr_userword

MODULE_EXEC	= asrdemo_with_abnf
MODULE_TARGET	= $(MODULE_EXEC)
LOCAL_INCLUDE	= -I$(BASEDIR)/../include
LOCAL_FLAGS	= $(LOCAL_INCLUDE) $(PIC_FLAG)
LIBS	:= -L$(BASEDIR-BIN) -lmsc -ldl -lpthread -lrt

MODULE_OBJ   = \
	$(MODULE_OUTPUT)/asrdemo_with_abnf.o

#common makefile foot
include $(BASEDIR)/scripts/rules.mk
