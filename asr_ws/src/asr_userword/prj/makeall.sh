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
    cd $BASEDIR/../Examples/$target
    make
done

