(defun fibonacci (n)
  (do* ((tmp 1 (+ x y))
	(x 1 y)
	(y 1 tmp)
	(count n (1- count)))
       ((= count 1) y)))

(format t "~{~a~#[~;, and ~:;, ~]~}" (mapcar #'fibonacci '(1 2 3 4 5 6 7 8 9 10)))
