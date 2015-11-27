
(cl:in-package :asdf)

(defsystem "facedetect-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "FacePosition" :depends-on ("_package_FacePosition"))
    (:file "_package_FacePosition" :depends-on ("_package"))
  ))