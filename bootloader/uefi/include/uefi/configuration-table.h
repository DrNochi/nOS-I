#pragma once

#include <uefi/table.h>

typedef struct EFI_CONFIGURATION_TABLE
{
    EFI_GUID VendorGuid;
    VOID *VendorTable;
} EFI_CONFIGURATION_TABLE;
