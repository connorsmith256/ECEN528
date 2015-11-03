#for i in $(ls -l benchmarks/*/*.dlx | sed -nre 's/.*benchmarks\/.*\/(.*)\.dlx/\1/p'); do
for benchmark in branch field gauss ldst queen solve test2; do
#for benchmark in field20; do 
  for history_bits in 0 1 2 3 4; do
    for btb_size in 1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16384 32768 65536; do
      echo "benchmark = $benchmark, history bits = $history_bits, btbSize = $btb_size"
      ./diff.sh dynamic:$history_bits:$btb_size $benchmark
    done
  done
  echo "benchmark = $benchmark, dp = static"
  ./diff.sh static $benchmark
  echo "benchmark = $benchmark, dp = none"
  ./diff.sh none $benchmark
  echo "benchmark = $benchmark, dp = perfect"
  ./diff.sh perfect $benchmark
done

