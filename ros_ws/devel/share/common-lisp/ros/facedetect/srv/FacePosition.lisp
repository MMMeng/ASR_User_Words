; Auto-generated. Do not edit!


(cl:in-package facedetect-srv)


;//! \htmlinclude FacePosition-request.msg.html

(cl:defclass <FacePosition-request> (roslisp-msg-protocol:ros-message)
  ((trigger
    :reader trigger
    :initarg :trigger
    :type cl:integer
    :initform 0))
)

(cl:defclass FacePosition-request (<FacePosition-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <FacePosition-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'FacePosition-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name facedetect-srv:<FacePosition-request> is deprecated: use facedetect-srv:FacePosition-request instead.")))

(cl:ensure-generic-function 'trigger-val :lambda-list '(m))
(cl:defmethod trigger-val ((m <FacePosition-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader facedetect-srv:trigger-val is deprecated.  Use facedetect-srv:trigger instead.")
  (trigger m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <FacePosition-request>) ostream)
  "Serializes a message object of type '<FacePosition-request>"
  (cl:let* ((signed (cl:slot-value msg 'trigger)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <FacePosition-request>) istream)
  "Deserializes a message object of type '<FacePosition-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'trigger) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<FacePosition-request>)))
  "Returns string type for a service object of type '<FacePosition-request>"
  "facedetect/FacePositionRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'FacePosition-request)))
  "Returns string type for a service object of type 'FacePosition-request"
  "facedetect/FacePositionRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<FacePosition-request>)))
  "Returns md5sum for a message object of type '<FacePosition-request>"
  "d2c05ccb640a33497a3b05a5ba135029")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'FacePosition-request)))
  "Returns md5sum for a message object of type 'FacePosition-request"
  "d2c05ccb640a33497a3b05a5ba135029")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<FacePosition-request>)))
  "Returns full string definition for message of type '<FacePosition-request>"
  (cl:format cl:nil "~%int32 trigger~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'FacePosition-request)))
  "Returns full string definition for message of type 'FacePosition-request"
  (cl:format cl:nil "~%int32 trigger~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <FacePosition-request>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <FacePosition-request>))
  "Converts a ROS message object to a list"
  (cl:list 'FacePosition-request
    (cl:cons ':trigger (trigger msg))
))
;//! \htmlinclude FacePosition-response.msg.html

(cl:defclass <FacePosition-response> (roslisp-msg-protocol:ros-message)
  ((x
    :reader x
    :initarg :x
    :type cl:float
    :initform 0.0)
   (y
    :reader y
    :initarg :y
    :type cl:float
    :initform 0.0))
)

(cl:defclass FacePosition-response (<FacePosition-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <FacePosition-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'FacePosition-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name facedetect-srv:<FacePosition-response> is deprecated: use facedetect-srv:FacePosition-response instead.")))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <FacePosition-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader facedetect-srv:x-val is deprecated.  Use facedetect-srv:x instead.")
  (x m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <FacePosition-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader facedetect-srv:y-val is deprecated.  Use facedetect-srv:y instead.")
  (y m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <FacePosition-response>) ostream)
  "Serializes a message object of type '<FacePosition-response>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <FacePosition-response>) istream)
  "Deserializes a message object of type '<FacePosition-response>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<FacePosition-response>)))
  "Returns string type for a service object of type '<FacePosition-response>"
  "facedetect/FacePositionResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'FacePosition-response)))
  "Returns string type for a service object of type 'FacePosition-response"
  "facedetect/FacePositionResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<FacePosition-response>)))
  "Returns md5sum for a message object of type '<FacePosition-response>"
  "d2c05ccb640a33497a3b05a5ba135029")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'FacePosition-response)))
  "Returns md5sum for a message object of type 'FacePosition-response"
  "d2c05ccb640a33497a3b05a5ba135029")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<FacePosition-response>)))
  "Returns full string definition for message of type '<FacePosition-response>"
  (cl:format cl:nil "float64 x~%float64 y~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'FacePosition-response)))
  "Returns full string definition for message of type 'FacePosition-response"
  (cl:format cl:nil "float64 x~%float64 y~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <FacePosition-response>))
  (cl:+ 0
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <FacePosition-response>))
  "Converts a ROS message object to a list"
  (cl:list 'FacePosition-response
    (cl:cons ':x (x msg))
    (cl:cons ':y (y msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'FacePosition)))
  'FacePosition-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'FacePosition)))
  'FacePosition-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'FacePosition)))
  "Returns string type for a service object of type '<FacePosition>"
  "facedetect/FacePosition")