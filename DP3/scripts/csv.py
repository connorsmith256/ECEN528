#!/u/cjs1993/python3/bin/python3

import sys, glob, os, re, statistics

config_dir = '../configs'
results_dir = '../results'
blacklist_file = '../analysis/blacklist'

def reduce(config, metric, func):
  values = []
  pattern = re.compile(metric + ' ')
  for benchmark in glob.iglob(results_dir + '/' + config + '/*.eio.gz.out'):
    for line in open(benchmark):
      if pattern.match(line):
        #print(benchmark, line)
        value = float(re.findall(r'\s+\d*\.?\d+', line)[0])
        values.append(value)
  #print(config, values)
  return func(values)

method = sys.argv[2]
if method == "mean":
  func = statistics.mean
elif method == "median":
  func = statistics.median
elif method == "min":
  func = min
elif method == "max":
  func = max

configs = [os.path.splitext(os.path.basename(filename))[0] for filename in glob.iglob('../configs/*.values')]
blacklist = [line.replace('\n', '') for line in open(blacklist_file)]
configs = [config for config in configs if not config in blacklist]
configs.sort()

columns = '_,'

# column titles
for config in configs:
  columns += config + ','
columns = columns[:-1]

print(columns)

# for each row/metric
for metric in open(sys.argv[1]):
  metric = metric.replace('\n', '')
  row = metric + ','

  for config in configs:
    value = reduce(config, metric, func)
    row += format(value, '.5f') + ','
  
  row = row[:-1]
  print(row)

print('\n')

