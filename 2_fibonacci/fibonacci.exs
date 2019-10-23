defmodule Fibonacci do
  def fib(one,two,n) do
    IO.puts two
    if n < 10, do: fib(two,one+two, n+1)
  end
end

Fibonacci.fib(1,1,1)
