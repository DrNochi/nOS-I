#include <uefi/uefi.h>
#include <uefi/status-codes.h>

EFI_STATUS EFIAPI efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
    SystemTable->ConOut->OutputString(SystemTable->ConOut, u"TESTTESTTESTTESTTESTTESTTESTTESTTESTTEST");

    SystemTable->ConIn->Reset(SystemTable->ConIn, FALSE);
    while (SystemTable->ConIn->ReadKeyStroke(SystemTable->ConIn, NULL) == EFI_NOT_READY) {}

    return EFI_SUCCESS;
}
