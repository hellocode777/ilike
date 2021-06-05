
(setq byte-compile-warnings '(cl-function))
(require 'cl)

(when (>= emacs-major-version 24)
  (require 'package)
  (add-to-list 'package-archives '("melpa" . "http://melpa.org/packages/"))
  (package-initialize)
  (package-refresh-contents)
  )

(defvar zzss/packages '(
			company
			evil
			evil-leader
			monokai-theme
			hungry-delete
			smex
			swiper
			counsel
			smartparens
			fzf
			) "Default packages")

(setq package-selected-packages zzss/packages)
      
(defun zzss/packages-installed-p ()
  (loop for pkg in zzss/packages
	when (not (package-installed-p pkg)) do (return nil)
	finally (return t)))

(unless (zzss/packages-installed-p)
  (message "%s" "Refreshing package database...")
  (package-refresh-contents)
  (dolist (pkg zzss/packages)
    (when (not (package-installed-p pkg))
      (package-install pkg))))


(global-company-mode)



(require 'evil-leader)
(global-evil-leader-mode)

(require 'evil)
(evil-mode t)

(require 'hungry-delete)
(global-hungry-delete-mode)

(require 'smartparens-config)
(smartparens-global-mode t)

(ivy-mode)
(setq ivy-use-virtual-buffers t)
(setq enable-recursive-minibuffers t)

(load-theme 'monokai t)

(provide 'init-packages)
