/* Flash OS Routines (Automagically Generated)
 * Copyright (c) 2009-2015 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

static const uint32_t template_flash_prog_blob[] = {
    0xE00ABE00, 0x062D780D, 0x24084068, 0xD3000040, 0x1E644058, 0x1C49D1FA, 0x2A001E52, 0x4770D1F2,
    0x48744975, 0x49766248, 0x60484874, 0x20054770, 0x06804974, 0x68086088, 0x431022c0, 0x68486008,
    0xd00207c0, 0x07c06848, 0x4770d1fc, 0x4c6ab5f8, 0x21016960, 0x61604308, 0x68504a69, 0x0489213f,
    0x21094388, 0x43080489, 0x20036050, 0x04804966, 0x12876088, 0x69206067, 0x69206920, 0x47b04e63,
    0x47a84d63, 0x6020209f, 0x606747a8, 0x692047a8, 0x69206921, 0x2940b2c9, 0xb2c0d127, 0x28154f5d,
    0x47b0d813, 0x21011d20, 0x60010249, 0x47a847b0, 0x60382000, 0x200247a8, 0x47b06038, 0x47804856,
    0x200147a8, 0x47a86020, 0x47b0e00f, 0x21ff4853, 0x60013101, 0x47a847b0, 0x60382002, 0x484e47b0,
    0x47a84780, 0x60202031, 0x47b047a8, 0x273547a8, 0x47a86027, 0x07806920, 0x47b0d405, 0x47a86027,
    0x07806920, 0x4a3ed5f9, 0x213f6850, 0x43880489, 0x0489211b, 0x60504308, 0xb510bdf8, 0x07802001,
    0x10c26801, 0x60014311, 0x49324c33, 0x4a346261, 0x60514932, 0x10826801, 0x60014311, 0x49312005,
    0x60880680, 0x22c06808, 0x60084310, 0x07c06848, 0x6848d002, 0xd1fc07c0, 0xff78f7ff, 0x21ff6960,
    0x43880209, 0x02892101, 0x61604308, 0xbd102000, 0x47702000, 0x47702000, 0x4c24b510, 0x482647a0,
    0x491d4780, 0x60082060, 0x47804821, 0x200047a0, 0xb510bd10, 0x49220300, 0x47880b00, 0xbd102000,
    0x460a4613, 0xb5104619, 0x4b1e0300, 0x47980b00, 0xbd102000, 0x4615b570, 0xb0842200, 0x92019200,
    0x92039202, 0xd2012910, 0xe000460c, 0x03062410, 0x0b364815, 0x4b154780, 0x46314622, 0x47984668,
    0x46694622, 0xf0004628, 0x2800f823, 0x2001d000, 0xbd70b004, 0x030f1300, 0x17fff000, 0x006db6c0,
    0x40001040, 0x40014000, 0x40001000, 0x00001dbb, 0x00001db1, 0x17fff008, 0x00001dcf, 0x17fff004,
    0x000023d3, 0x00002271, 0x00001efd, 0x00002037, 0x4604b530, 0x46032000, 0x1c5be000, 0xd2034293,
    0x5ccd5ce0, 0xd0f81b40, 0x0000bd30, 0x00000000
};

// Start address of flash
static const uint32_t flash_start = 0x18001000;
// Size of flash
static const uint32_t flash_size = 0x000ff000;

/**
* List of start and size for each size of flash sector - even indexes are start, odd are size
* The size will apply to all sectors between the listed address and the next address
* in the list.
* The last pair in the list will have sectors starting at that address and ending
* at address flash_start + flash_size.
*/
static const uint32_t sectors_info[] = {
    0x18001000, 0x00001000,
};

static const program_target_t flash = {
    0x0010011b, // Init
    0x00100171, // UnInit
    0x00100179, // EraseChip
    0x00100193, // EraseSector
    0x001001a1, // ProgramPage
	0x001001b5, //Verify

    // BKPT : start of blob + 1
    // RSB  : blob start + header + rw data offset
    // RSP  : stack pointer
    {
        0x00100001,
        0x0010024c,
        0x00100500
    },

    0x00100000 + 0x00000A00,  // mem buffer location
    0x00100000,               // location to write prog_blob in target RAM
    sizeof(template_flash_prog_blob),   // prog_blob size
    template_flash_prog_blob,           // address of prog_blob
    0x00001000       // ram_to_flash_bytes_to_be_written
};