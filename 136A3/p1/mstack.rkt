#lang racket

;; A Mutable Stack ADT in Racket (INTERFACE)

;; INTEGRITY STATEMENT (modify if necessary)
;; I received help from the following sources:
;; None. I am the sole author of this work 

;; sign this statement by removing the line below and entering your name
;; Name: Chenzheng Su
;; login ID: c28su

(provide create-mstack mstack-push! mstack-pop! mstack-top mstack-empty?)

;; A Mutable Stack ADT
(struct mstack (lst) #:mutable)

;; (create-mstack) creates a new mutable stack
;; create-mstack: Void -> MStack
(define (create-mstack)
  (mstack empty))

;; (mstack-top s) produces the top item of mstack s
;; mstack-top: MStack -> Any
;; requires: s is non-empty
(define (mstack-top s)
  (first (mstack-lst s)))

;; (mstack-empty? s) determines if mstack s is empty
;; mstack-empty?: MStack -> Bool
(define (mstack-empty? s)
  (empty? (mstack-lst s)))

;; Complete following functions

;; (mstack-push! i s) adds i to the top of mstack s
;; mstack-push!: Any MStack -> Void
;; effects: mutates s
(define (mstack-push! i s)
  (set-mstack-lst! s (cons i (mstack-lst s))))

;; (mstack-pop! s) removes the top item from mstack s
;;   and produces the item popped
;; mstack-pop!: MStack -> Any
;; requires: s is non-empty
;; effects: mutates s
(define (mstack-pop! s)
	(define c (first (mstack-lst s)))
  (set-mstack-lst! s (rest (mstack-lst s)))
  c)
