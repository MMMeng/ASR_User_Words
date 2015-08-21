; Auto-generated. Do not edit!


(cl:in-package asr_usercommand-srv)


;//! \htmlinclude usercommand-request.msg.html

(cl:defclass <usercommand-request> (roslisp-msg-protocol:ros-message)
  ((num
    :reader num
    :initarg :num
    :type cl:integer
    :initform 0))
)

(cl:defclass usercommand-request (<usercommand-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <usercommand-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'usercommand-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name asr_usercommand-srv:<usercommand-request> is deprecated: use asr_usercommand-srv:usercommand-request instead.")))

(cl:ensure-generic-function 'num-val :lambda-list '(m))
(cl:defmethod num-val ((m <usercommand-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader asr_usercommand-srv:num-val is deprecated.  Use asr_usercommand-srv:num instead.")
  (num m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <usercommand-request>) ostream)
  "Serializes a message object of type '<usercommand-request>"
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <usercommand-request>) istream)
  "Deserializes a message object of type '<usercommand-request>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<usercommand-request>)))
  "Returns string type for a service object of type '<usercommand-request>"
  "asr_usercommand/usercommandRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'usercommand-request)))
  "Returns string type for a service object of type 'usercommand-request"
  "asr_usercommand/usercommandRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<usercommand-request>)))
  "Returns md5sum for a message object of type '<usercommand-request>"
  "71ac060476c0905d0416477df3715d0f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'usercommand-request)))
  "Returns md5sum for a message object of type 'usercommand-request"
  "71ac060476c0905d0416477df3715d0f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<usercommand-request>)))
  "Returns full string definition for message of type '<usercommand-request>"
  (cl:format cl:nil "int64 num~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'usercommand-request)))
  "Returns full string definition for message of type 'usercommand-request"
  (cl:format cl:nil "int64 num~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <usercommand-request>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <usercommand-request>))
  "Converts a ROS message object to a list"
  (cl:list 'usercommand-request
    (cl:cons ':num (num msg))
))
;//! \htmlinclude usercommand-response.msg.html

(cl:defclass <usercommand-response> (roslisp-msg-protocol:ros-message)
  ((command
    :reader command
    :initarg :command
    :type cl:string
    :initform ""))
)

(cl:defclass usercommand-response (<usercommand-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <usercommand-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'usercommand-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name asr_usercommand-srv:<usercommand-response> is deprecated: use asr_usercommand-srv:usercommand-response instead.")))

(cl:ensure-generic-function 'command-val :lambda-list '(m))
(cl:defmethod command-val ((m <usercommand-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader asr_usercommand-srv:command-val is deprecated.  Use asr_usercommand-srv:command instead.")
  (command m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <usercommand-response>) ostream)
  "Serializes a message object of type '<usercommand-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'command))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'command))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <usercommand-response>) istream)
  "Deserializes a message object of type '<usercommand-response>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<usercommand-response>)))
  "Returns string type for a service object of type '<usercommand-response>"
  "asr_usercommand/usercommandResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'usercommand-response)))
  "Returns string type for a service object of type 'usercommand-response"
  "asr_usercommand/usercommandResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<usercommand-response>)))
  "Returns md5sum for a message object of type '<usercommand-response>"
  "71ac060476c0905d0416477df3715d0f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'usercommand-response)))
  "Returns md5sum for a message object of type 'usercommand-response"
  "71ac060476c0905d0416477df3715d0f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<usercommand-response>)))
  "Returns full string definition for message of type '<usercommand-response>"
  (cl:format cl:nil "string command~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'usercommand-response)))
  "Returns full string definition for message of type 'usercommand-response"
  (cl:format cl:nil "string command~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <usercommand-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'command))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <usercommand-response>))
  "Converts a ROS message object to a list"
  (cl:list 'usercommand-response
    (cl:cons ':command (command msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'usercommand)))
  'usercommand-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'usercommand)))
  'usercommand-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'usercommand)))
  "Returns string type for a service object of type '<usercommand>"
  "asr_usercommand/usercommand")