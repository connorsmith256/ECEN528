bp_type=$1
benchmark=$2

./run.sh mine $bp_type $benchmark &> output/mine.out
sed -i 's/mydlx>/golddlxBP>/g' output/mine.out
./run.sh gold $bp_type $benchmark &> output/gold.out
diff -q --suppress-common-lines output/mine.out output/gold.out
