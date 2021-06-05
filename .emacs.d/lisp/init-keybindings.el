(with-eval-after-load 'evil-maps
  (define-key evil-normal-state-map (kbd "L") 'evil-end-of-line)
  (define-key evil-normal-state-map (kbd "H") 'evil-beginning-of-line))





(global-set-key (kbd "C-c s") 'swiper)





(evil-leader/set-leader "<SPC>")

(evil-leader/set-key
  "a" 'org-agenda
  "b" 'switch-to-buffer
  "f" 'counsel-find-file
  "g" 'counsel-git
  "k" 'kill-buffer
  )
(provide 'init-keybindings)
