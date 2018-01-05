#include <euler/test.h>
#include "euler/modular_arithmetic.h"

void test_shift_mod()
{
    assert(shift_mod(0x0000000000949aff, 10, 0x66efee8f13017fe5) == 0x00000002526bfc00);
    assert(shift_mod(0x0000000000949aff, 40, 0x076a9548db4a18c7) == 0x0047554ede361074);
    assert(shift_mod(0x0000000ec722a23f, 10, 0x1cf17c461cf17c46) == 0x00003b1c8a88fc00);
    assert(shift_mod(0x0000000dc8b0aacf, 37, 0x75255fc625567bf8) == 0x6a7e13818babaa18);
    assert(shift_mod(0x0000b78b26fe2c1f, 10, 0xcbc4c0e0d2ac91cb) == 0x02de2c9bf8b07c00);
    assert(shift_mod(0x0000d1a887dfe237, 40, 0x48367a7e558b8648) == 0x36cb67ccc8b1f3c0);
    assert(shift_mod(0xb95ff168ac7f97e0, 93, 0x399fcdc2d99fcdc2) == 0x221842663a61c38e);
    assert(shift_mod(0xf36503e4f36503e4, 43, 0x0f1c311d13017fe5) == 0x01ca7e4004606b8f);
}

void test_mult_mod()
{
    assert(
        0x14e254a838dc51d0 ==
        mult_mod(0x00000000d08ca38e, 0x000000008830b9c2, 0x5a1013ed8e893dcc));
    assert(
        0x51180cfd6df308f1 ==
        mult_mod(0x000000006acdd987, 0x27f51e4600000000, 0x5211f8b1ce5b76a9));
    assert(
        0x007fb9a9cce9b6e0 ==
        mult_mod(0x6d5548af00000000, 0x00000000ba1617ce, 0x0416f93ca2e4a178));
    assert(
        0x101d2c5f5ce8cadf ==
        mult_mod(0xde8992e600000000, 0x00000000a353bdba, 0x1e4ba4f65a8e0f27));
    assert(
        0x0f6e82c6a74c73f7 ==
        mult_mod(0x00000000f25cb4be, 0x9e70991d9e70991d, 0x3bc0712cc16c5857));
    assert(
        0x09b6e259ae092f50 ==
        mult_mod(0x75ee21d000000000, 0x7acc88ffec6ef8d2, 0x0ddb12b79d175d18));
    assert(
        0x3c064aeef18343aa ==
        mult_mod(0xa1267d4fc377f858, 0x4ec23a7e4ec23a7e, 0x6ecc991e81cca999));
}

void test_pow_mod()
{
    assert(
        0x04ff249b24b0f0a7 ==
        pow_mod(0xdbe8ef2e8810d2a9, 0x0000000000004f13, 0x107369250bd858c3));
    assert(
        0x03d4f97ddd805f24 ==
        pow_mod(0xca7901d255eccf77, 0x000000002610248e, 0x0f1c62b5ef1c62b5));
    assert(
        0x131c1c32131c1c32 ==
        pow_mod(0x9fbb62ca9fbb62ca, 0x00002ba4d74e2ba4, 0x17621a1d17621a1d));
    assert(
        0x0c3c6cbd11a07a16 ==
        pow_mod(0x8f7a17078f7a1707, 0xcb3d4a819eb6565f, 0x389698a6dd3f8dd5));
    assert(
        0x090ccd555d1c3970 ==
        pow_mod(0xc04ba12ec04ba12e, 0xfd335a9d82361136, 0x0ac36db6c16d2f90));
}

void test_sum_mod()
{
    uint64_t data[] = {
        0x2d3cf55f5d0323dc,
        0x2600751c67ff3c1e,
        0x29571f6549efabd6,
        0x0e962241d3074a21,
        0xa1be9b50c1f0ce91,
        0x07076cc65afccf07,
        0x4e4b34c48c474c2d,
        0xadec7a85c3887a95,
        0xf845addf061ad0a0,
        0xee654f61d81bf3d3,
        0xcab77070212bc44c,
        0x2d7d153fe43e3bc1};

    assert(0x074f7b2204381deb == sum_mod(data, 12, 0x2dfd718c1d136808));
    assert(0x513bf4df3aa1d86b == sum_mod(data, 12, 0x65265421d4a47888));
    assert(0x197cf2a14009f089 == sum_mod(data, 12, 0x3c7454c0f32843ba));
    assert(0x02079ea59516a466 == sum_mod(data, 11, 0x08e92a6b156f8fc3));
    assert(0x128732b41fe55bc6 == sum_mod(data, 10, 0x16d9dee3ef3911d8));
}

TESTS() {
    RUN(test_shift_mod);
    RUN(test_mult_mod);
    RUN(test_pow_mod);
    RUN(test_sum_mod);
}
