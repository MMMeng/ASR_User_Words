; Auto-generated. Do not edit!


(cl:in-package asr_usercommand-srv)


;//! \htmlinclude UserCommand-request.msg.html

(cl:defclass <UserCommand-request> (roslisp-msg-protocol:ros-message)
  ((num
    :reader num
    :initarg :num
    :type cl:integer
    :initform 0))
)

(cl:defclass UserCommand-request (<UserCommand-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <UserCommand-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'UserCommand-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name asr_usercommand-srv:<UserCommand-request> is deprecated: use asr_usercommand-srv:UserCommand-request instead.")))

(cl:ensure-generic-function 'num-val :lambda-list '(m))
(cl:defmethod num-val ((m <UserCommand-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader asr_usercommand-srv:num-val is deprecated.  Use asr_usercommand-srv:num instead.")
  (num m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <UserCommand-request>) ostream)
  "Serializes a message object of type '<UserCommand-request>"
  (cl:let* ((signed (cl:slot-value msg 'num)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <UserCommand-request>) istream)
  "Deserializes a message object of type '<UserCommand-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'num) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<UserCommand-request>)))
  "Returns string type for a service object of type '<UserCommand-request>"
  "asr_usercommand/UserCommandRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'UserCommand-request)))
  "Returns string type for a service object of type 'UserCommand-request"
  "asr_usercommand/UserCommandRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<UserCommand-request>)))
  "Returns md5sum for a message object of type '<UserCommand-request>"
  "71ac060476c0905d0416477df3715d0f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'UserCommand-request)))
  "Returns md5sum for a message object of type 'UserCommand-request"
  "71ac060476c0905d0416477df3715d0f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<UserCommand-request>)))
  "Returns full string definition for message of type '<UserCommand-request>"
  (cl:format cl:nil "int64 num~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'UserCommand-request)))
  "Returns full string definition for message of type 'UserCommand-request"
  (cl:format cl:nil "int64 num~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <UserCommand-request>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <UserCommand-request>))
  "Converts a ROS message object to a list"
  (cl:list 'UserCommand-request
    (cl:cons ':num (num msg))
))
;//! \htmlinclude UserCommand-response.msg.html

(cl:defclass <UserCommand-response> (roslisp-msg-protocol:ros-message)
  ((command
    :reader command
    :initarg :command
    :type cl:string
    :initform ""))
)

(cl:defclass UserCommand-response (<UserCommand-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <UserCommand-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'UserCommand-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name asr_usercommand-srv:<UserCommand-response> is deprecated: use asr_usercommand-srv:UserCommand-response instead.")))

(cl:ensure-generic-function 'command-val :lambda-list '(m))
(cl:defmethod command-val ((m <UserCommand-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader asr_usercommand-srv:command-val is deprecated.  Use asr_usercommand-srv:command instead.")
  (command m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <UserCommand-response>) ostream)
  "Serializes a message object of type '<UserCommand-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'command))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'command))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <UserCommand-response>) istream)
  "Deserializes a message object of type '<UserCommand-response>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'command) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'command) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<UserCommand-response>)))
  "Returns string type for a service object of type '<UserCommand-response>"
  "asr_usercommand/UserCommandResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'UserCommand-response)))
  "Returns string type for a service object of type 'UserCommand-response"
  "asr_usercommand/UserCommandResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<UserCommand-response>)))
  "Returns md5sum for a message object of type '<UserCommand-response>"
  "71ac060476c0905d0416477df3715d0f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'UserCommand-response)))
  "Returns md5sum for a message object of type 'UserCommand-response"
  "71ac060476c0905d0416477df3715d0f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<UserCommand-response>)))
  "Returns full string definition for message of type '<UserCommand-response>"
  (cl:format cl:nil "string command~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'UserCommand-response)))
  "Returns full string definition for message of type 'UserCommand-response"
  (cl:format cl:nil "string command~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <UserCommand-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'command))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <UserCommand-response>))
  "Converts a ROS message object to a list"
  (cl:list 'UserCommand-response
    (cl:cons ':command (command msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'UserCommand)))
  'UserCommand-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'UserCommand)))
  'UserCommand-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'UserCommand)))
  "Returns string type for a service object of type '<UserCommand>"
  "asr_usercommand/UserCommand")