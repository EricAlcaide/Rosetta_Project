(defun fact (n)
  (do* ((count n (1- count))
	(result n (* result count)))
       ((= count 1) result)))
