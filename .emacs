;; Uncomment this next line if you want line numbers on the left side
;(global-linum-mode 1)
(setq undo-limit 80000)
(global-set-key "\C-c\C-v" 'compile)
(setq line-number-mode t)
(setq column-number-mode t)
(display-time)
(global-font-lock-mode t)
(setq font-lock-maximum-decoration t)
(show-paren-mode)


(global-set-key "\C-x\C-g" 'goto-line)


; Automatically set compilation mode to
; move to an error when you move the point over it
(add-hook 'compilation-mode-hook
 (lambda ()
   (progn
     (next-error-follow-minor-mode))))

;Automatically go to the first error
(setq compilation-auto-jump-to-first-error t)
(defun set-window-undedicated-p (window flag)
  "Never set window dedicated."
  flag)

(advice-add 'set-window-dedicated-p :override #'set-window-undedicated-p)
