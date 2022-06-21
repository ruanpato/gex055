# 🖥️ CLI - Binomial Distribution #

## 📑 Summary ##

- [🖥️ CLI - Binomial Distribution](#️-cli---binomial-distribution)
  - [📑 Summary](#-summary)
  - [🏃‍♀️ Running](#️-running)
  - [References](#references)

## 🏃‍♀️ Running ##

> MAX N == 20;

```bash
gfortran binomial-distribution.f90 -Wall -O3 -o binomial-distribution && ./binomial-distribution-fortran
```

```bash
gcc binomial-distribution.c -Wall -O3 -lm -o binomial-distribution-c && ./binomial-distribution-c
```

## References ##

- <https://www.ifsc.usp.br/~hoyos/courses/2019/7600017/gfortran.pdf>
- <https://www.pgroup.com/resources/docs/18.7/pdf/pgi18fortref.pdf>
- <https://programmingforresearchers.leeds.ac.uk/fortran/section-3/page-2/>
- <https://www.nsc.liu.se/~boein/f77to90/a3.html>
