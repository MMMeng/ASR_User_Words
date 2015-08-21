
(cl:in-package :asdf)

(defsystem "asr_usercommand-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "UserCommand" :depends-on ("_package_UserCommand"))
    (:file "_package_UserCommand" :depends-on ("_package"))
  ))