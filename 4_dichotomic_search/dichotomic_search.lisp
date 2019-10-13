(defpackage :dichotomic-search
  (:use :cl)
  (:export :dichotomic-search))
(in-package :dichotomic-search)

(defmacro dicho (seq item gt lt)
  `(do* ((left 0)
	 (right (1- (length ,seq)))
	 (middle (floor (/ (+ left right) 2))
		 (floor (/ (+ left right) 2))))
	((> left right) nil)
     (cond ((,lt (elt ,seq middle) ,item) (setf left (1+ middle)))
	   ((,gt (elt ,seq middle) ,item) (setf right (1- middle)))
	   (t (return (elt ,seq middle))))))

(defgeneric dichotomic-search (seq item))

(defmethod dichotomic-search (seq (item number))
  (dicho seq item > <))

(defmethod dichotomic-search (seq (item character))
  (dicho seq item char> char<))
