program binomial_distribution
   implicit none
   real(kind=16) :: n, x, p, q;
   character(len=2) :: condition;
   print *, "Please input n: ";
   read *, n;
   print *, "Please input x: ";
   read *, x;
   print *, "Please input p: ";
   read *, p;
   q = 1 - p;
   print *, "Please input condition (e.g. '=', '>=', '>, '<=', '<'): ";
   read *, condition;


   print *, "- n: ", n;
   print *, "- x: ", x;
   print *, "- p: ", p;
   print *, "- q: ", q;
   print *, "- condition: ", condition;
   real(kind=16) :: res = calculate(n, x, p, q);
   print *, "- P(", x, ") = ", res;
end program binomial_distribution

recursive function factorial(n) result(fact)
   integer(kind=16), allocatable:: fact;
   integer(kind=16), intent(in):: n;
   if (n <= 0) then
      fact = 1;
   else
      fact = n*factorial(n-1);
   end if
end function factorial

real(kind=16) function calculate(n, x, p, q)
   real(kind=16) :: div;
   div = (factorial(int(n, kind=16)) / (factorial(int(n-x, kind=16))));
   calculate = real(div * factorial(x)) * p**x * q**(n-x), kind=16;
end function calculate
