build: init bin/main.efi

init:
    mkdir -p bin/intermediate/

bin/intermediate/main.o: src/main.c
    clang -c -m64 -fpie -fno-exceptions -fno-rtti -I ../include -D "EFIAPI=__attribute__((ms_abi))" $^ -o $@

bin/intermediate/main.so: bin/intermediate/main.o
    ld -pie -nostdlib -s -T build/main.ld $^ -o $@

bin/main.efi: bin/intermediate/main.so
    objcopy --target=pei-x86-64 --subsystem 10 -j .text -j .data -j .reloc $^ $@ 
