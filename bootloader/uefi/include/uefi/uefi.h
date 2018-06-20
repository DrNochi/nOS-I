#pragma once

#include <uefi/system-table.h>
#include <uefi/status-codes.h>

//
// UEFI image entry point
//
typedef EFI_STATUS(EFIAPI *EFI_IMAGE_ENTRY_POINT)(
    IN EFI_HANDLE ImageHandle,
    IN EFI_SYSTEM_TABLE *SystemTable);
