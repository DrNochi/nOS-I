#pragma once

//
// UEFI success codes
//
#define EFI_SUCCESS 0

//
// UEFI error codes
//
#define EFI_LOAD_ERROR ((1 << (sizeof(UINTN) * 8 - 1)) | (1))
#define EFI_INVALID_PARAMETER ((1 << (sizeof(UINTN) * 8 - 1)) | (2))
#define EFI_UNSUPPORTED ((1 << (sizeof(UINTN) * 8 - 1)) | (3))
#define EFI_BAD_BUFFER_SIZE ((1 << (sizeof(UINTN) * 8 - 1)) | (4))
#define EFI_BUFFER_TOO_SMALL ((1 << (sizeof(UINTN) * 8 - 1)) | (5))
#define EFI_NOT_READY ((1 << (sizeof(UINTN) * 8 - 1)) | (6))
#define EFI_DEVICE_ERROR ((1 << (sizeof(UINTN) * 8 - 1)) | (7))
#define EFI_WRITE_PROTECTED ((1 << (sizeof(UINTN) * 8 - 1)) | (8))
#define EFI_OUT_OF_RESOURCES ((1 << (sizeof(UINTN) * 8 - 1)) | (9))
#define EFI_VOLUME_CORRUPTED ((1 << (sizeof(UINTN) * 8 - 1)) | (10))
#define EFI_VOLUME_FULL ((1 << (sizeof(UINTN) * 8 - 1)) | (11))
#define EFI_NO_MEDIA ((1 << (sizeof(UINTN) * 8 - 1)) | (12))
#define EFI_MEDIA_CHANGED ((1 << (sizeof(UINTN) * 8 - 1)) | (13))
#define EFI_NOT_FOUND ((1 << (sizeof(UINTN) * 8 - 1)) | (14))
#define EFI_ACCESS_DENIED ((1 << (sizeof(UINTN) * 8 - 1)) | (15))
#define EFI_NO_RESPONSE ((1 << (sizeof(UINTN) * 8 - 1)) | (16))
#define EFI_NO_MAPPING ((1 << (sizeof(UINTN) * 8 - 1)) | (17))
#define EFI_TIMEOUT ((1 << (sizeof(UINTN) * 8 - 1)) | (18))
#define EFI_NOT_STARTED ((1 << (sizeof(UINTN) * 8 - 1)) | (19))
#define EFI_ALREADY_STARTED ((1 << (sizeof(UINTN) * 8 - 1)) | (20))
#define EFI_ABORTED ((1 << (sizeof(UINTN) * 8 - 1)) | (21))
#define EFI_ICMP_ERROR ((1 << (sizeof(UINTN) * 8 - 1)) | (22))
#define EFI_TFTP_ERROR ((1 << (sizeof(UINTN) * 8 - 1)) | (23))
#define EFI_PROTOCOL_ERROR ((1 << (sizeof(UINTN) * 8 - 1)) | (24))
#define EFI_INCOMPATIBLE_VERSION ((1 << (sizeof(UINTN) * 8 - 1)) | (25))
#define EFI_SECURITY_VIOLATION ((1 << (sizeof(UINTN) * 8 - 1)) | (26))
#define EFI_CRC_ERROR ((1 << (sizeof(UINTN) * 8 - 1)) | (27))
#define EFI_END_OF_MEDIA ((1 << (sizeof(UINTN) * 8 - 1)) | (28))
#define EFI_END_OF_FILE ((1 << (sizeof(UINTN) * 8 - 1)) | (31))
#define EFI_INVALID_LANGUAGE ((1 << (sizeof(UINTN) * 8 - 1)) | (32))
#define EFI_COMPROMISED_DATA ((1 << (sizeof(UINTN) * 8 - 1)) | (33))
#define EFI_IP_ADDRESS_CONFLICT ((1 << (sizeof(UINTN) * 8 - 1)) | (34))
#define EFI_HTTP_ERROR ((1 << (sizeof(UINTN) * 8 - 1)) | (35))

//
// UEFI warning codes
//
#define EFI_WARN_UNKNOWN_GLYPH 1
#define EFI_WARN_DELETE_FAILURE 2
#define EFI_WARN_WRITE_FAILURE 3
#define EFI_WARN_BUFFER_TOO_SMALL 4
#define EFI_WARN_STALE_DATA 5
#define EFI_WARN_FILE_SYSTEM 6
#define EFI_WARN_RESET_REQUIRED 7
