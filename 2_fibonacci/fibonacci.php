<?php
/*
 * @Author: Alex Smoliankin 
 * @Email: ashustrich@gmail.com
 */

function fib_helper($number) {
	$previous = 0;
	$current = 1;

	while ($number-- > 0) {
		[$previous, $current] = [$current, $previous + $current];
	}

	return $current;
}

function fibonacci(){
	print join(" ", array_map("fib_helper", range(0, 10)));
}

fibonacci();
