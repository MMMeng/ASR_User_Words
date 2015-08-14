#! /bin/bash
export BASEDIR=$PWD

MODULE_TARGET=(			\
	asrdemo				\
	asrdemo_with_abnf		\
	iatdemo				\
	iatdemo_with_multi-result	\
	ttsdemo				\
	ttsdemo_with_number		\
	ttsdemo_with_speechmark)

for target in ${MODULE_TARGET[*]}
do
    if test -d $BASEDIR/../Examples/$target/xebug
        then rm -r $BASEDIR/../Examples/$target/xebug
	echo delete $BASEDIR/../Examples/$target/xebug
    fi

    if test -d $BASEDIR/../Examples/$target/xelease
        then rm -r $BASEDIR/../Examples/$target/xelease
	echo delete $BASEDIR/../Examples/$target/xelease
    fi

    if test -f ../bin/$target
        then rm ../bin/$target
	echo delete ../bin/$target
    fi
done
echo clean done!
