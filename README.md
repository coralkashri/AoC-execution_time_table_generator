# Advent of Code - Execution Time Table Generator

This tool produces an execution time table for days part of Advent of Code puzzles.<br>
Usage example: https://github.com/coralkashri/AOC/blob/master/src/2020/README.md.

* [Run Command](#run-command)
* [Output Example](#output-example)
* [Input File Syntax](#input-file-syntax)
  + [Legal input lines](#legal-input-lines)
  + [Legal input days](#legal-input-days)
  + [Illegal input lines](#illegal-input-lines)

## Run Command
```AoC_execution_time_table_generator path/to/input/file.ext```

## Output Example

Produced using [input_file_2](./input_file_examples/input_file_2.txt).

| Day | First Part | Second Part |
| --- | ---------- | ----------- |
| 1 |  50 milliseconds |  5 seconds, 50 milliseconds |
| 2 |  50 milliseconds |  5 seconds, 50 milliseconds |
| 3 |  |  5 seconds, 50 milliseconds |
| 4 |  50 milliseconds |  5 seconds, 50 milliseconds |
| 5 |  |  |
| 6 |  50 milliseconds |  |
| 7 |  50 milliseconds |  5 seconds, 50 milliseconds |
| 8 |  50 milliseconds |  5 seconds, 50 milliseconds |
| 9 |  50 milliseconds |  5 seconds, 50 milliseconds |
| 10 |  50 milliseconds |  5 seconds, 50 milliseconds |
| 11 |  50 milliseconds |  5 seconds, 50 milliseconds |
| 12 |  50 milliseconds |  5 seconds, 50 milliseconds |
| 13 |  50 milliseconds |  5 seconds, 50 milliseconds |
| 14 |  50 milliseconds |  5 seconds, 50 milliseconds |
| 15 |  50 milliseconds |  |
| 16 |  |  5 seconds, 50 milliseconds |
| 17 |  50 milliseconds |  5 seconds, 50 milliseconds |
| 18 |  50 milliseconds |  5 seconds, 50 milliseconds |
| 19 |  50 milliseconds |  5 seconds, 50 milliseconds |
| 20 |  50 milliseconds |  5 seconds, 50 milliseconds |
| 21 |  50 milliseconds |  5 seconds, 50 milliseconds |
| 22 |  50 milliseconds |  5 seconds, 50 milliseconds |
| 23 |  50 milliseconds |  5 seconds, 50 milliseconds |
| 24 |  50 milliseconds |  5 seconds, 50 milliseconds |
| 25 |  50 milliseconds |  5 seconds, 50 milliseconds |

## Input File Syntax

... {day number (1-25)} ...<br>
(optional)First: time details<br>
(optional)Second: time details<br>

### Legal input lines
* Days 24 // Day 24
* 21 // Day 21
* FirSt: 34milli // first part with data: ' 34milli'

### Legal input days
* Day 21<br>
  First:<br> 
  Second: 34milli
* 4<br>
  Second: 34milli
* 3 day<br>
  fiRst: 34milli
* day of advent - 12<br>
  second: 34milli<br>
  fiRst: 34milli

### Illegal input lines
* Day 56 // Max day is 25
* 26 // Max day is 25
* third: 2 milliseconds // Unrecognized part (only use first / second)
* Seconds // Unrecognized part
* Day: 5 // Unrecognized part