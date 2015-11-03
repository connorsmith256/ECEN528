make

sim=$1
bp_type=$2
benchmark=$3

if [[ $1 == "mine" ]]; then
    sim="mydlx"
else
    sim="golddlxBP"
fi

if [[ -f temp.in ]]; then
    rm temp.in
fi

touch temp.in
echo "l benchmarks/$benchmark/$benchmark.dlx" >> temp.in
echo "v" >> temp.in
echo "e" >> temp.in
echo "t" >> temp.in
echo "quit" >> temp.in

printf '\033[1;33m'
cat temp.in | ./$sim --bp=$bp_type
printf '\033[0m'
rm temp.in
