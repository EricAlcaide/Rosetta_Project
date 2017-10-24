%% @doc Prints the 10 first numbers of the Fibonacci Series starting @ the second 1
%% @author Fredrik August Madsen-Malmo

-module(fibonacci).
-export([fibonacci/0]).

fibonacci() ->
	fibonacci(10, 1, 1).

fibonacci(0, _, _) ->
	ok;
fibonacci(Iterations, Prev, Curr) ->
	io:format("~w ", [Curr]),
	fibonacci(Iterations - 1, Curr, Prev + Curr).
