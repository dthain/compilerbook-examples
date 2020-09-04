#!/bin/sh

# How to use this test script:

# Put all of your tests into a directory like "tests/scanner".
# Name the good tests goodXX.bminor and the bad tests badXX.bminor.
# Then use run-tests.sh and give the location of the compiler
# executable, the command-line option, and the test directory.
# This script will run all of the tests, and show you the
# details of which ones failed.

# For example:
#     run-tests.sh $HOME/mycompiler/bminor -scan tests/scanner

if [ $# -ne 3 ]
then
	echo "Usage: $0 <compiler> <mode> <test-dir>"
	exit 1
fi

COMPILER=$1
MODE=$2
TESTDIR=$3

LINES=-------------------------------------------

for testfile in ${TESTDIR}/good*.bminor
do
	if ${COMPILER} ${MODE} $testfile > $testfile.out 2>&1
	then
		echo "$testfile success (as expected)"
	else
		echo "$testfile failure (INCORRECT)"
		echo ${LINES}
		echo Test Input:
		echo ${LINES}
		cat $testfile
		echo ${LINES}
		echo Your Output:
		echo ${LINES}
		cat $testfile.out
		echo ${LINES}
	fi
done

for testfile in ${TESTDIR}/bad*.bminor
do
	if ${COMPILER} ${MODE} $testfile > $testfile.out 2>&1
	then
		echo "$testfile success (INCORRECT)"
		echo ${LINES}
		echo Test Input:
		echo ${LINES}
		cat $testfile
		echo ${LINES}
		echo Your Output:
		echo ${LINES}
		cat $testfile.out
		echo ${LINES}
	else
		echo "$testfile failure (as expected)"
	fi
done

