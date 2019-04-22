#lang racket

;; This module provides functions to be translated into C

(provide polyeval selector max3 sumsqr1 sumsqr2 sumsqr3 sameparity)

;; (polyeval a b c x) evaluates ax^2 + bx + c
;; polyeval: Int Int Int Int -> Int

;; (selector a x y) produces x if a is non-zero, and y otherwise
;; selector: Int Int Int -> Int

;; (max3 a b c) produces the max of a, b and c
;; max3: Int Int Int -> Int

;; (sumsqr1 n) produces the sum of 1^2, 2^2, .... n^2
;; sumsqr1: Nat -> Nat

;; (sumsqr2 n) produces the sum of 1^2, 2^2, .... n^2
;; sumsqr2: Nat -> Nat

;; (sumsqr3 n) produces the sum of 1^2, 2^2, .... n^2
;; sumsqr3: Nat -> Nat

;; (sameparity a b) produces 1 if a and b have the same parity (odd/even)
;;   or 0 otherwise
;; sameparity: Int -> Int

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; IMPLEMENTATION

;; see documenation above

(define (polyeval a b c x)
  (+ (* a x x) (* b x) c))

(define (selector a x y)
  (cond [(zero? a) y]
        [else x]))

(define (max3 a b c)
  (cond [(and (>= a b) (>= a c)) a]
        [(and (>= b a) (>= b c)) b]
        [else c]))

(define (sumsqr1 n)
  (cond [(zero? n) 0]
        [else (+ (* n n) (sumsqr1 (- n 1)))]))

;; (sumsqr2acc n sofar) produces the sum of 1^2, 2^2, .... n^2 + sofar
;; sumsqr1: Nat Int -> Int

(define (sumsqr2acc n sofar)
  (cond [(zero? n) sofar]
        [else (sumsqr2acc (- n 1) (+ (* n n) sofar))]))

(define (sumsqr2 n)
  (sumsqr2acc n 0))

(define (sumsqr3 n)
  (/ (* n (+ n 1) (+ (* 2 n) 1)) 6))

(define (sameparity a b)
  (cond [(or (and (even? a) (even? b))
         (and (odd? a) (odd? b)))
         1]
        [else 0]))

;; Oh, no! C doesn't have an even? function
;; don't define your own... practice using the C % operator instead.
