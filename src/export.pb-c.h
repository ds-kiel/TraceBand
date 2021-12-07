/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: export.proto */

#ifndef PROTOBUF_C_export_2eproto__INCLUDED
#define PROTOBUF_C_export_2eproto__INCLUDED

#include <protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1000000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1004000 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct TemporaryExposureKeyExport TemporaryExposureKeyExport;
typedef struct SignatureInfo SignatureInfo;
typedef struct TemporaryExposureKey TemporaryExposureKey;
typedef struct TEKSignatureList TEKSignatureList;
typedef struct TEKSignature TEKSignature;


/* --- enums --- */

/*
 * Data type representing why this key was published.
 */
typedef enum _TemporaryExposureKey__ReportType {
  /*
   * Never returned by the client API.
   */
  TEMPORARY_EXPOSURE_KEY__REPORT_TYPE__UNKNOWN = 0,
  TEMPORARY_EXPOSURE_KEY__REPORT_TYPE__CONFIRMED_TEST = 1,
  TEMPORARY_EXPOSURE_KEY__REPORT_TYPE__CONFIRMED_CLINICAL_DIAGNOSIS = 2,
  TEMPORARY_EXPOSURE_KEY__REPORT_TYPE__SELF_REPORT = 3,
  TEMPORARY_EXPOSURE_KEY__REPORT_TYPE__RECURSIVE = 4,
  /*
   * Used to revoke a key, never returned by client API.
   */
  TEMPORARY_EXPOSURE_KEY__REPORT_TYPE__REVOKED = 5
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(TEMPORARY_EXPOSURE_KEY__REPORT_TYPE)
} TemporaryExposureKey__ReportType;

/* --- messages --- */

/*
 * Protobuf definition for exports of confirmed temporary exposure keys.
 * The full file format is documented under "Exposure Key Export File Format
 * and Verification" at https://www.google.com/covid19/exposurenotifications/
 * These files have a 16-byte, space-padded header before the protobuf data
 * starts. They will be contained in a zip archive, alongside a signature
 * file verifying the contents.
 */
struct  TemporaryExposureKeyExport
{
  ProtobufCMessage base;
  /*
   * Time window of keys in this file based on arrival to server, in UTC
   * seconds. start_timestamp, end_timestamp, and batch_num must be unique
   * at any given snapshot of the index for a server. If multiple
   * files are used for a specific time period, and batch_num/batch_size
   * are both 1 (See below), then offsetting the end_timestamp is the
   * suggested method for forcing uniqueness.
   */
  protobuf_c_boolean has_start_timestamp;
  uint64_t start_timestamp;
  protobuf_c_boolean has_end_timestamp;
  uint64_t end_timestamp;
  /*
   * Region for which these keys came from (e.g., country)
   */
  char *region;
  /*
   * E.g., Batch 2 of 10. Ordinal, 1-based numbering.
   * Note: Not yet supported on iOS. Use values of 1 for both.
   */
  protobuf_c_boolean has_batch_num;
  int32_t batch_num;
  protobuf_c_boolean has_batch_size;
  int32_t batch_size;
  /*
   * Information about signatures
   * If there are multiple entries, they must be ordered in descending
   * time order by signing key effective time (most recent one first).
   * There is a limit of 10 signature infos per export file (mobile OS may
   * not check anything after that).
   */
  size_t n_signature_infos;
  SignatureInfo **signature_infos;
  /*
   * The TemporaryExposureKeys for initial release of keys.
   * Keys should be included in this list for initial release,
   * whereas revised or revoked keys should go in revised_keys.
   */
  size_t n_keys;
  TemporaryExposureKey **keys;
  /*
   * TemporaryExposureKeys that have changed status.
   * Keys should be included in this list if they have changed status
   * or have been revoked.
   */
  size_t n_revised_keys;
  TemporaryExposureKey **revised_keys;
};
#define TEMPORARY_EXPOSURE_KEY_EXPORT__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&temporary_exposure_key_export__descriptor) \
    , 0, 0, 0, 0, NULL, 0, 0, 0, 0, 0,NULL, 0,NULL, 0,NULL }


struct  SignatureInfo
{
  ProtobufCMessage base;
  /*
   * Key version for rollovers
   * Must be in character class [a-zA-Z0-9_]. E.g., 'v1'
   */
  char *verification_key_version;
  /*
   * Alias with which to identify public key to be used for verification
   * Must be in character class [a-zA-Z0-9_]
   * For cross-compatibility with Apple, use MCC
   * (https://en.wikipedia.org/wiki/Mobile_country_code).
   */
  char *verification_key_id;
  /*
   * ASN.1 OID for Algorithm Identifier. Supported algorithms are
   * either 1.2.840.10045.4.3.2 or 1.2.840.10045.4.3.4
   */
  char *signature_algorithm;
};
#define SIGNATURE_INFO__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&signature_info__descriptor) \
    , NULL, NULL, NULL }


struct  TemporaryExposureKey
{
  ProtobufCMessage base;
  /*
   * Key of infected user
   */
  protobuf_c_boolean has_key_data;
  ProtobufCBinaryData key_data;
  /*
   * Varying risks associated with exposure depending on type of verification
   * Ignored by the v1.5 client API when report_type is set.
   */
  protobuf_c_boolean has_transmission_risk_level PROTOBUF_C__DEPRECATED;
  int32_t transmission_risk_level PROTOBUF_C__DEPRECATED;
  /*
   * The interval number since epoch for which a key starts
   */
  protobuf_c_boolean has_rolling_start_interval_number;
  int32_t rolling_start_interval_number;
  /*
   * Increments of 10 minutes describing how long a key is valid
   */
  /*
   * defaults to 24 hours
   */
  protobuf_c_boolean has_rolling_period;
  int32_t rolling_period;
  /*
   * Type of diagnosis associated with a key.
   */
  protobuf_c_boolean has_report_type;
  TemporaryExposureKey__ReportType report_type;
  /*
   * Number of days elapsed between symptom onset and the TEK being used.
   * E.g. 2 means TEK is 2 days after onset of symptoms.
   */
  protobuf_c_boolean has_days_since_onset_of_symptoms;
  int32_t days_since_onset_of_symptoms;
};
#define TEMPORARY_EXPOSURE_KEY__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&temporary_exposure_key__descriptor) \
    , 0, {0,NULL}, 0, 0, 0, 0, 0, 144, 0, TEMPORARY_EXPOSURE_KEY__REPORT_TYPE__UNKNOWN, 0, 0 }


struct  TEKSignatureList
{
  ProtobufCMessage base;
  /*
   * When there are multiple signatures, they must be sorted in time order
   * by first effective date for the signing key in descending order.
   * The most recent effective signing key must appear first.
   * There is a limit of 10 signature infos per export file (mobile OS may
   * not check anything after that).
   */
  size_t n_signatures;
  TEKSignature **signatures;
};
#define TEKSIGNATURE_LIST__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&teksignature_list__descriptor) \
    , 0,NULL }


struct  TEKSignature
{
  ProtobufCMessage base;
  /*
   * Info about the signing key, version, algorithm, etc.
   */
  SignatureInfo *signature_info;
  /*
   * E.g., Batch 2 of 10
   * Must match fields from TemporaryExposureKeyExport, see
   * documentation on that message.
   */
  protobuf_c_boolean has_batch_num;
  int32_t batch_num;
  protobuf_c_boolean has_batch_size;
  int32_t batch_size;
  /*
   * Signature in X9.62 format (ASN.1 SEQUENCE of two INTEGER fields)
   */
  protobuf_c_boolean has_signature;
  ProtobufCBinaryData signature;
};
#define TEKSIGNATURE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&teksignature__descriptor) \
    , NULL, 0, 0, 0, 0, 0, {0,NULL} }


/* TemporaryExposureKeyExport methods */
void   temporary_exposure_key_export__init
                     (TemporaryExposureKeyExport         *message);
size_t temporary_exposure_key_export__get_packed_size
                     (const TemporaryExposureKeyExport   *message);
size_t temporary_exposure_key_export__pack
                     (const TemporaryExposureKeyExport   *message,
                      uint8_t             *out);
size_t temporary_exposure_key_export__pack_to_buffer
                     (const TemporaryExposureKeyExport   *message,
                      ProtobufCBuffer     *buffer);
TemporaryExposureKeyExport *
       temporary_exposure_key_export__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   temporary_exposure_key_export__free_unpacked
                     (TemporaryExposureKeyExport *message,
                      ProtobufCAllocator *allocator);
/* SignatureInfo methods */
void   signature_info__init
                     (SignatureInfo         *message);
size_t signature_info__get_packed_size
                     (const SignatureInfo   *message);
size_t signature_info__pack
                     (const SignatureInfo   *message,
                      uint8_t             *out);
size_t signature_info__pack_to_buffer
                     (const SignatureInfo   *message,
                      ProtobufCBuffer     *buffer);
SignatureInfo *
       signature_info__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   signature_info__free_unpacked
                     (SignatureInfo *message,
                      ProtobufCAllocator *allocator);
/* TemporaryExposureKey methods */
void   temporary_exposure_key__init
                     (TemporaryExposureKey         *message);
size_t temporary_exposure_key__get_packed_size
                     (const TemporaryExposureKey   *message);
size_t temporary_exposure_key__pack
                     (const TemporaryExposureKey   *message,
                      uint8_t             *out);
size_t temporary_exposure_key__pack_to_buffer
                     (const TemporaryExposureKey   *message,
                      ProtobufCBuffer     *buffer);
TemporaryExposureKey *
       temporary_exposure_key__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   temporary_exposure_key__free_unpacked
                     (TemporaryExposureKey *message,
                      ProtobufCAllocator *allocator);
/* TEKSignatureList methods */
void   teksignature_list__init
                     (TEKSignatureList         *message);
size_t teksignature_list__get_packed_size
                     (const TEKSignatureList   *message);
size_t teksignature_list__pack
                     (const TEKSignatureList   *message,
                      uint8_t             *out);
size_t teksignature_list__pack_to_buffer
                     (const TEKSignatureList   *message,
                      ProtobufCBuffer     *buffer);
TEKSignatureList *
       teksignature_list__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   teksignature_list__free_unpacked
                     (TEKSignatureList *message,
                      ProtobufCAllocator *allocator);
/* TEKSignature methods */
void   teksignature__init
                     (TEKSignature         *message);
size_t teksignature__get_packed_size
                     (const TEKSignature   *message);
size_t teksignature__pack
                     (const TEKSignature   *message,
                      uint8_t             *out);
size_t teksignature__pack_to_buffer
                     (const TEKSignature   *message,
                      ProtobufCBuffer     *buffer);
TEKSignature *
       teksignature__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   teksignature__free_unpacked
                     (TEKSignature *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*TemporaryExposureKeyExport_Closure)
                 (const TemporaryExposureKeyExport *message,
                  void *closure_data);
typedef void (*SignatureInfo_Closure)
                 (const SignatureInfo *message,
                  void *closure_data);
typedef void (*TemporaryExposureKey_Closure)
                 (const TemporaryExposureKey *message,
                  void *closure_data);
typedef void (*TEKSignatureList_Closure)
                 (const TEKSignatureList *message,
                  void *closure_data);
typedef void (*TEKSignature_Closure)
                 (const TEKSignature *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor temporary_exposure_key_export__descriptor;
extern const ProtobufCMessageDescriptor signature_info__descriptor;
extern const ProtobufCMessageDescriptor temporary_exposure_key__descriptor;
extern const ProtobufCEnumDescriptor    temporary_exposure_key__report_type__descriptor;
extern const ProtobufCMessageDescriptor teksignature_list__descriptor;
extern const ProtobufCMessageDescriptor teksignature__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_export_2eproto__INCLUDED */
