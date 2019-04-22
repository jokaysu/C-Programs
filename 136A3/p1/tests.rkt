#lang racket

(require "mstack.rkt")

;; Example tests
;; init
(define ms (create-mstack))
;; tests
(mstack-empty? ms)
;; mutate mqp
(mstack-push! "item0" ms)
;; tests
(not (mstack-empty? ms))
(equal? (mstack-top ms) "item0")
;; mutate mstack
(mstack-pop! ms)
;; tests
(mstack-empty? ms)
;; reset
(set! ms (create-mstack))

;; Add your own tests..
