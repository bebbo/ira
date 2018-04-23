/*
 * constants.c
 *
 *  Created on: 1 may 2015
 *      Author   : Tim Ruehsen, Frank Wille, Nicolas Bastien
 *      Project  : IRA  -  680x0 Interactive ReAssembler
 *      Part     : constants.c
 *      Purpose  : Contains data for IRA
 *      Copyright: (C)1993-1995 Tim Ruehsen
 *                 (C)2009-2015 Frank Wille, (C)2014-2017 Nicolas Bastien
 */

#include <stdio.h>
#include <stdint.h>

#include "ira.h"

/* Indices of cpuname array are directly linked to CPU defines */
const char cpuname[][8] = {"MC68000", "MC68010", "MC68020", "MC68030", "MC68040", "MC68060", "MC68851", "MC68881", "MC68882"};

/* Number of elements in the cpuname array above */
const size_t cpuname_number = sizeof(cpuname) / 8;

/* All data are now gathered into an unique array */
/* note: family field is used to execute specific piece of code (i.e checking extension word with LPSTOP) */
Opcode_t instructions[] = {
/* family                   opcode[8]  result  mask    srcadr                                                                                      destadr                                                                 flags                               cputype */
{OPC_BITFIELD,              "BF",      0xe8c0, 0xf8c0, MODE_SPECIFIC,                                                                              MODE_SPECIFIC,                                                          OPF_ONE_MORE_WORD,                  M020UP},
{OPC_ROTATE_SHIFT_MEMORY,   "ASL",     0xe1c0, 0xffc0, MODE_NONE,                                                                                  A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,             OPF_OPERAND_WORD,                   M680x0},
{OPC_ROTATE_SHIFT_REGISTER, "ASL",     0xe100, 0xf118, MODE_IN_LOWER_BYTE|MODE_ROTATE_SHIFT,                                                       MODE_IN_LOWER_BYTE|MODE_DREG_DIRECT,                                    OPF_APPEND_SIZE,                    M680x0},
{OPC_ROTATE_SHIFT_MEMORY,   "ASR",     0xe0c0, 0xffc0, MODE_NONE,                                                                                  A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,             OPF_OPERAND_WORD,                   M680x0},
{OPC_ROTATE_SHIFT_REGISTER, "ASR",     0xe000, 0xf118, MODE_IN_LOWER_BYTE|MODE_ROTATE_SHIFT,                                                       MODE_IN_LOWER_BYTE|MODE_DREG_DIRECT,                                    OPF_APPEND_SIZE,                    M680x0},
{OPC_ROTATE_SHIFT_MEMORY,   "LSL",     0xe3c0, 0xffc0, MODE_NONE,                                                                                  A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,             OPF_OPERAND_WORD,                   M680x0},
{OPC_ROTATE_SHIFT_REGISTER, "LSL",     0xe108, 0xf118, MODE_IN_LOWER_BYTE|MODE_ROTATE_SHIFT,                                                       MODE_IN_LOWER_BYTE|MODE_DREG_DIRECT,                                    OPF_APPEND_SIZE,                    M680x0},
{OPC_ROTATE_SHIFT_MEMORY,   "LSR",     0xe2c0, 0xffc0, MODE_NONE,                                                                                  A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,             OPF_OPERAND_WORD,                   M680x0},
{OPC_ROTATE_SHIFT_REGISTER, "LSR",     0xe008, 0xf118, MODE_IN_LOWER_BYTE|MODE_ROTATE_SHIFT,                                                       MODE_IN_LOWER_BYTE|MODE_DREG_DIRECT,                                    OPF_APPEND_SIZE,                    M680x0},
{OPC_ROTATE_SHIFT_MEMORY,   "ROXL",    0xe5c0, 0xffc0, MODE_NONE,                                                                                  A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,             OPF_OPERAND_WORD,                   M680x0},
{OPC_ROTATE_SHIFT_REGISTER, "ROXL",    0xe110, 0xf118, MODE_IN_LOWER_BYTE|MODE_ROTATE_SHIFT,                                                       MODE_IN_LOWER_BYTE|MODE_DREG_DIRECT,                                    OPF_APPEND_SIZE,                    M680x0},
{OPC_ROTATE_SHIFT_MEMORY,   "ROXR",    0xe4c0, 0xffc0, MODE_NONE,                                                                                  A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,             OPF_OPERAND_WORD,                   M680x0},
{OPC_ROTATE_SHIFT_REGISTER, "ROXR",    0xe010, 0xf118, MODE_IN_LOWER_BYTE|MODE_ROTATE_SHIFT,                                                       MODE_IN_LOWER_BYTE|MODE_DREG_DIRECT,                                    OPF_APPEND_SIZE,                    M680x0},
{OPC_ROTATE_SHIFT_MEMORY,   "ROL",     0xe7c0, 0xffc0, MODE_NONE,                                                                                  A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,             OPF_OPERAND_WORD,                   M680x0},
{OPC_ROTATE_SHIFT_REGISTER, "ROL",     0xe118, 0xf118, MODE_IN_LOWER_BYTE|MODE_ROTATE_SHIFT,                                                       MODE_IN_LOWER_BYTE|MODE_DREG_DIRECT,                                    OPF_APPEND_SIZE,                    M680x0},
{OPC_ROTATE_SHIFT_MEMORY,   "ROR",     0xe6c0, 0xffc0, MODE_NONE,                                                                                  A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,             OPF_OPERAND_WORD,                   M680x0},
{OPC_ROTATE_SHIFT_REGISTER, "ROR",     0xe018, 0xf118, MODE_IN_LOWER_BYTE|MODE_ROTATE_SHIFT,                                                       MODE_IN_LOWER_BYTE|MODE_DREG_DIRECT,                                    OPF_APPEND_SIZE,                    M680x0},
{OPC_NONE,                  "ILLEGAL", 0x4afc, 0xffff, MODE_NONE,                                                                                  MODE_NONE,                                                              OPF_OPERAND_BYTE,                   M680x0},
{OPC_NONE,                  "NOP",     0x4e71, 0xffff, MODE_NONE,                                                                                  MODE_NONE,                                                              OPF_OPERAND_BYTE,                   M680x0},
{OPC_NONE,                  "RESET",   0x4e70, 0xffff, MODE_NONE,                                                                                  MODE_NONE,                                                              OPF_OPERAND_BYTE,                   M680x0},
{OPC_RTE,                   "RTE",     0x4e73, 0xffff, MODE_NONE,                                                                                  MODE_NONE,                                                              OPF_OPERAND_BYTE,                   M680x0},
{OPC_RTR,                   "RTR",     0x4e77, 0xffff, MODE_NONE,                                                                                  MODE_NONE,                                                              OPF_OPERAND_BYTE,                   M680x0},
{OPC_RTS,                   "RTS",     0x4e75, 0xffff, MODE_NONE,                                                                                  MODE_NONE,                                                              OPF_OPERAND_BYTE,                   M680x0},
{OPC_RTD,                   "RTD",     0x4e74, 0xffff, MODE_NONE,                                                                                  MODE_IN_LOWER_BYTE|MODE_SP_DISPLACE_W,                                  OPF_OPERAND_BYTE,                   M010UP},
{OPC_NONE,                  "STOP",    0x4e72, 0xffff, MODE_IN_LOWER_BYTE|MODE_IMMEDIATE,                                                          MODE_NONE,                                                              OPF_OPERAND_WORD,                   M680x0},
{OPC_NONE,                  "TRAPV",   0x4e76, 0xffff, MODE_NONE,                                                                                  MODE_NONE,                                                              OPF_OPERAND_BYTE,                   M680x0},
{OPC_NONE,                  "MOVEC",   0x4e7a, 0xfffe, MODE_NONE,                                                                                  MODE_IN_LOWER_BYTE|MODE_MOVEC,                                          OPF_OPERAND_LONG,                   M010UP},
{OPC_NONE,                  "BKPT",    0x4848, 0xfff8, MODE_NONE,                                                                                  MODE_IN_LOWER_BYTE|MODE_BKPT,                                           OPF_OPERAND_BYTE,                   M010UP},
{OPC_NONE,                  "SWAP",    0x4840, 0xfff8, MODE_NONE,                                                                                  MODE_IN_LOWER_BYTE|MODE_DREG_DIRECT,                                    OPF_OPERAND_BYTE,                   M680x0},
{OPC_NONE,                  "LINK.W",  0x4e50, 0xfff8, MODE_IN_LOWER_BYTE|MODE_AREG_DIRECT,                                                        MODE_IN_LOWER_BYTE|MODE_SP_DISPLACE_W,                                  OPF_OPERAND_WORD,                   M680x0},
{OPC_NONE,                  "LINK.L",  0x4808, 0xfff8, MODE_IN_LOWER_BYTE|MODE_AREG_DIRECT,                                                        MODE_IN_LOWER_BYTE|MODE_SP_DISPLACE_L,                                  OPF_OPERAND_WORD,                   M020UP},
{OPC_NONE,                  "UNLK",    0x4e58, 0xfff8, MODE_NONE,                                                                                  MODE_IN_LOWER_BYTE|MODE_AREG_DIRECT,                                    OPF_OPERAND_WORD,                   M680x0},
{OPC_NONE,                  "EXT.W",   0x4880, 0xfff8, MODE_NONE,                                                                                  MODE_IN_LOWER_BYTE|MODE_DREG_DIRECT,                                    OPF_OPERAND_WORD,                   M680x0},
{OPC_NONE,                  "EXT.L",   0x48c0, 0xfff8, MODE_NONE,                                                                                  MODE_IN_LOWER_BYTE|MODE_DREG_DIRECT,                                    OPF_OPERAND_LONG,                   M680x0},
{OPC_NONE,                  "EXTB.L",  0x49c0, 0xfff8, MODE_NONE,                                                                                  MODE_IN_LOWER_BYTE|MODE_DREG_DIRECT,                                    OPF_OPERAND_LONG,                   M020UP},
{OPC_NONE,                  "MOVE.L",  0x4e68, 0xfff8, MODE_IN_LOWER_BYTE|MODE_USP,                                                                MODE_IN_LOWER_BYTE|MODE_AREG_DIRECT,                                    OPF_OPERAND_LONG,                   M680x0},
{OPC_NONE,                  "MOVE.L",  0x4e60, 0xfff8, MODE_IN_LOWER_BYTE|MODE_AREG_DIRECT,                                                        MODE_IN_LOWER_BYTE|MODE_USP,                                            OPF_OPERAND_LONG,                   M680x0},
{OPC_NONE,                  "TRAP",    0x4e40, 0xfff0, MODE_NONE,                                                                                  MODE_IN_LOWER_BYTE|MODE_TRAP,                                           OPF_OPERAND_BYTE,                   M680x0},
{OPC_DIVL,                  "DIV",     0x4c40, 0xffc0, D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND|IMMED,       MODE_IN_LOWER_BYTE|MODE_MUL_DIV_LONG,                                   OPF_OPERAND_LONG|OPF_ONE_MORE_WORD, M020UP},
{OPC_MULL,                  "MUL",     0x4c00, 0xffc0, D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND|IMMED,       MODE_IN_LOWER_BYTE|MODE_MUL_DIV_LONG,                                   OPF_OPERAND_LONG|OPF_ONE_MORE_WORD, M020UP},
{OPC_NONE,                  "TAS",     0x4ac0, 0xffc0, MODE_NONE,                                                                                  D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,       OPF_OPERAND_BYTE,                   M680x0},
{OPC_JMP,                   "JMP",     0x4ec0, 0xffc0, MODE_NONE,                                                                                  A_IND|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND,                    OPF_OPERAND_WORD,                   M680x0},
{OPC_JSR,                   "JSR",     0x4e80, 0xffc0, MODE_NONE,                                                                                  A_IND|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND,                    OPF_OPERAND_WORD,                   M680x0},
{OPC_PEA,                   "PEA",     0x4840, 0xffc0, MODE_NONE,                                                                                  A_IND|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND,                    OPF_OPERAND_BYTE,                   M680x0},
{OPC_NONE,                  "NBCD",    0x4800, 0xffc0, MODE_NONE,                                                                                  D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,       OPF_OPERAND_BYTE,                   M680x0},
{OPC_NONE,                  "MOVE",    0x44c0, 0xffc0, D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND|IMMED,       MODE_IN_LOWER_BYTE|MODE_CCR,                                            OPF_OPERAND_WORD,                   M680x0},
{OPC_NONE,                  "MOVE",    0x46c0, 0xffc0, D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND|IMMED,       MODE_IN_LOWER_BYTE|MODE_SR,                                             OPF_OPERAND_WORD,                   M680x0},
{OPC_NONE,                  "MOVE",    0x40c0, 0xffc0, MODE_IN_LOWER_BYTE|MODE_SR,                                                                 D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,       OPF_OPERAND_WORD,                   M680x0},
{OPC_NONE,                  "MOVE",    0x42c0, 0xffc0, MODE_IN_LOWER_BYTE|MODE_CCR,                                                                D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,       OPF_OPERAND_WORD,                   M010UP},
{OPC_MOVEM,                 "MOVEM.W", 0x4880, 0xffc0, MODE_IN_LOWER_BYTE|MODE_MOVEM,                                                              A_IND|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,                        OPF_OPERAND_WORD|OPF_ONE_MORE_WORD, M680x0},
{OPC_NONE,                  "MOVEM.W", 0x4c80, 0xffc0, A_IND|A_IND_POST|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND,                             MODE_IN_LOWER_BYTE|MODE_MOVEM,                                          OPF_OPERAND_WORD|OPF_ONE_MORE_WORD, M680x0},
{OPC_MOVEM,                 "MOVEM.L", 0x48c0, 0xffc0, MODE_IN_LOWER_BYTE|MODE_MOVEM,                                                              A_IND|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,                        OPF_OPERAND_LONG|OPF_ONE_MORE_WORD, M680x0},
{OPC_NONE,                  "MOVEM.L", 0x4cc0, 0xffc0, A_IND|A_IND_POST|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND,                             MODE_IN_LOWER_BYTE|MODE_MOVEM,                                          OPF_OPERAND_LONG|OPF_ONE_MORE_WORD, M680x0},
{OPC_LEA,                   "LEA",     0x41c0, 0xf1c0, A_IND|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND,                                        MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_AREG_DIRECT,                  OPF_OPERAND_BYTE,                   M680x0},
{OPC_NONE,                  "CHK.W",   0x4180, 0xf1c0, D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND|IMMED,       MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_DREG_DIRECT,                  OPF_OPERAND_WORD,                   M680x0},
{OPC_NONE,                  "CHK.L",   0x4100, 0xf1c0, D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND|IMMED,       MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_DREG_DIRECT,                  OPF_OPERAND_LONG,                   M020UP},
{OPC_NONE,                  "CLR",     0x4200, 0xff00, MODE_NONE,                                                                                  D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,       OPF_APPEND_SIZE,                    M680x0},
{OPC_TST,                   "TST",     0x4a00, 0xff00, D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,                           MODE_NONE,                                                              OPF_APPEND_SIZE,                    M680x0},
{OPC_NONE,                  "NOT",     0x4600, 0xff00, MODE_NONE,                                                                                  D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,       OPF_APPEND_SIZE,                    M680x0},
{OPC_NONE,                  "NEG",     0x4400, 0xff00, MODE_NONE,                                                                                  D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,       OPF_APPEND_SIZE,                    M680x0},
{OPC_NONE,                  "NEGX",    0x4000, 0xff00, MODE_NONE,                                                                                  D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,       OPF_APPEND_SIZE,                    M680x0},
{OPC_NONE,                  "ADDA.W",  0xd0c0, 0xf1c0, D_DIR|A_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND|IMMED, MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_AREG_DIRECT,                  OPF_OPERAND_WORD,                   M680x0},
{OPC_NONE,                  "ADDA.L",  0xd1c0, 0xf1c0, D_DIR|A_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND|IMMED, MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_AREG_DIRECT,                  OPF_OPERAND_LONG,                   M680x0},
{OPC_NONE,                  "ADDX",    0xd100, 0xf138, MODE_IN_LOWER_BYTE|MODE_DREG_DIRECT,                                                        MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_DREG_DIRECT,                  OPF_APPEND_SIZE,                    M680x0},
{OPC_NONE,                  "ADDX",    0xd108, 0xf138, MODE_IN_LOWER_BYTE|MODE_AREG_INDIRECT_PRE,                                                  MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_AREG_INDIRECT_PRE,            OPF_APPEND_SIZE,                    M680x0},
{OPC_NONE,                  "ADD",     0xd100, 0xf100, MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_DREG_DIRECT,                                      A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,             OPF_APPEND_SIZE,                    M680x0},
{OPC_NONE,                  "ADD",     0xd000, 0xf100, D_DIR|A_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND|IMMED, MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_DREG_DIRECT,                  OPF_APPEND_SIZE,                    M680x0},
{OPC_NONE,                  "EXG",     0xc140, 0xf1f8, MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_DREG_DIRECT,                                      MODE_IN_LOWER_BYTE|MODE_DREG_DIRECT,                                    OPF_OPERAND_LONG,                   M680x0},
{OPC_NONE,                  "EXG",     0xc148, 0xf1f8, MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_AREG_DIRECT,                                      MODE_IN_LOWER_BYTE|MODE_AREG_DIRECT,                                    OPF_OPERAND_LONG,                   M680x0},
{OPC_NONE,                  "EXG",     0xc188, 0xf1f8, MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_DREG_DIRECT,                                      MODE_IN_LOWER_BYTE|MODE_AREG_DIRECT,                                    OPF_OPERAND_LONG,                   M680x0},
{OPC_NONE,                  "ABCD",    0xc100, 0xf1f8, MODE_IN_LOWER_BYTE|MODE_DREG_DIRECT,                                                        MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_DREG_DIRECT,                  OPF_OPERAND_BYTE,                   M680x0},
{OPC_NONE,                  "ABCD",    0xc108, 0xf1f8, MODE_IN_LOWER_BYTE|MODE_AREG_INDIRECT_PRE,                                                  MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_AREG_INDIRECT_PRE,            OPF_OPERAND_BYTE,                   M680x0},
{OPC_NONE,                  "MULS",    0xc1c0, 0xf1c0, D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND|IMMED,       MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_DREG_DIRECT,                  OPF_OPERAND_WORD,                   M680x0},
{OPC_NONE,                  "MULU",    0xc0c0, 0xf1c0, D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND|IMMED,       MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_DREG_DIRECT,                  OPF_OPERAND_WORD,                   M680x0},
{OPC_NONE,                  "AND",     0xc100, 0xf100, MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_DREG_DIRECT,                                      A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,             OPF_APPEND_SIZE,                    M680x0},
{OPC_NONE,                  "AND",     0xc000, 0xf100, D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND|IMMED,       MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_DREG_DIRECT,                  OPF_APPEND_SIZE,                    M680x0},
{OPC_NONE,                  "CMPA.W",  0xb0c0, 0xf1c0, D_DIR|A_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND|IMMED, MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_AREG_DIRECT,                  OPF_OPERAND_WORD,                   M680x0},
{OPC_NONE,                  "CMPA.L",  0xb1c0, 0xf1c0, D_DIR|A_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND|IMMED, MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_AREG_DIRECT,                  OPF_OPERAND_LONG,                   M680x0},
{OPC_NONE,                  "CMPM",    0xb108, 0xf138, MODE_IN_LOWER_BYTE|MODE_AREG_INDIRECT_POST,                                                 MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_AREG_INDIRECT_POST,           OPF_APPEND_SIZE,                    M680x0},
{OPC_NONE,                  "CMP",     0xb000, 0xf100, D_DIR|A_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND|IMMED, MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_DREG_DIRECT,                  OPF_APPEND_SIZE,                    M680x0},
{OPC_NONE,                  "EOR",     0xb100, 0xf100, MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_DREG_DIRECT,                                      D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,       OPF_APPEND_SIZE,                    M680x0},
{OPC_PACK_UNPACK,           "PACK",    0x8148, 0xf1f8, MODE_IN_LOWER_BYTE|MODE_AREG_INDIRECT_PRE,                                                  MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_AREG_INDIRECT_PRE,            OPF_OPERAND_WORD|OPF_ONE_MORE_WORD, M020UP},
{OPC_PACK_UNPACK,           "PACK",    0x8140, 0xf1f8, MODE_IN_LOWER_BYTE|MODE_DREG_DIRECT,                                                        MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_DREG_DIRECT,                  OPF_OPERAND_WORD|OPF_ONE_MORE_WORD, M020UP},
{OPC_PACK_UNPACK,           "UNPK",    0x8188, 0xf1f8, MODE_IN_LOWER_BYTE|MODE_AREG_INDIRECT_PRE,                                                  MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_AREG_INDIRECT_PRE,            OPF_OPERAND_WORD|OPF_ONE_MORE_WORD, M020UP},
{OPC_PACK_UNPACK,           "UNPK",    0x8180, 0xf1f8, MODE_IN_LOWER_BYTE|MODE_DREG_DIRECT,                                                        MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_DREG_DIRECT,                  OPF_OPERAND_WORD|OPF_ONE_MORE_WORD, M020UP},
{OPC_NONE,                  "SBCD",    0x8100, 0xf1f8, MODE_IN_LOWER_BYTE|MODE_DREG_DIRECT,                                                        MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_DREG_DIRECT,                  OPF_OPERAND_BYTE,                   M680x0},
{OPC_NONE,                  "SBCD",    0x8108, 0xf1f8, MODE_IN_LOWER_BYTE|MODE_AREG_INDIRECT_PRE,                                                  MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_AREG_INDIRECT_PRE,            OPF_OPERAND_BYTE,                   M680x0},
{OPC_NONE,                  "DIVS",    0x81c0, 0xf1c0, D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND|IMMED,       MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_DREG_DIRECT,                  OPF_OPERAND_WORD,                   M680x0},
{OPC_NONE,                  "DIVU",    0x80c0, 0xf1c0, D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND|IMMED,       MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_DREG_DIRECT,                  OPF_OPERAND_WORD,                   M680x0},
{OPC_NONE,                  "OR",      0x8100, 0xf100, MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_DREG_DIRECT,                                      A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,             OPF_APPEND_SIZE,                    M680x0},
{OPC_NONE,                  "OR",      0x8000, 0xf100, D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND|IMMED,       MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_DREG_DIRECT,                  OPF_APPEND_SIZE,                    M680x0},
{OPC_MOVE,                  "MOVE.B",  0x1000, 0xf000, D_DIR|A_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND|IMMED, D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,       OPF_OPERAND_BYTE,                   M680x0},
{OPC_NONE,                  "MOVEA.W", 0x3040, 0xf1c0, D_DIR|A_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND|IMMED, MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_AREG_DIRECT,                  OPF_OPERAND_WORD,                   M680x0},
{OPC_MOVE,                  "MOVE.W",  0x3000, 0xf000, D_DIR|A_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND|IMMED, D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,       OPF_OPERAND_WORD,                   M680x0},
{OPC_MOVEAL,                "MOVEA.L", 0x2040, 0xf1c0, D_DIR|A_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND|IMMED, MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_AREG_DIRECT,                  OPF_OPERAND_LONG,                   M680x0},
{OPC_MOVE,                  "MOVE.L",  0x2000, 0xf000, D_DIR|A_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND|IMMED, D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,       OPF_OPERAND_LONG,                   M680x0},
{OPC_NONE,                  "MOVEQ",   0x7000, 0xf100, MODE_IN_LOWER_BYTE|MODE_MOVEQ,                                                              MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_DREG_DIRECT,                  OPF_OPERAND_BYTE,                   M680x0},
{OPC_NONE,                  "SUBA.W",  0x90c0, 0xf1c0, D_DIR|A_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND|IMMED, MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_AREG_DIRECT,                  OPF_OPERAND_WORD,                   M680x0},
{OPC_NONE,                  "SUBA.L",  0x91c0, 0xf1c0, D_DIR|A_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND|IMMED, MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_AREG_DIRECT,                  OPF_OPERAND_LONG,                   M680x0},
{OPC_NONE,                  "SUBX",    0x9100, 0xf138, MODE_IN_LOWER_BYTE|MODE_DREG_DIRECT,                                                        MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_DREG_DIRECT,                  OPF_APPEND_SIZE,                    M680x0},
{OPC_NONE,                  "SUBX",    0x9108, 0xf138, MODE_IN_LOWER_BYTE|MODE_AREG_INDIRECT_PRE,                                                  MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_AREG_INDIRECT_PRE,            OPF_APPEND_SIZE,                    M680x0},
{OPC_NONE,                  "SUB",     0x9100, 0xf100, MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_DREG_DIRECT,                                      A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,             OPF_APPEND_SIZE,                    M680x0},
{OPC_NONE,                  "SUB",     0x9000, 0xf100, D_DIR|A_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND|IMMED, MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_DREG_DIRECT,                  OPF_APPEND_SIZE,                    M680x0},
{OPC_NONE,                  "MOVEP",   0x0188, 0xf1f8, MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_DREG_DIRECT,                                      MODE_IN_LOWER_BYTE|MODE_AREG_INDIRECT_D16,                              OPF_OPERAND_WORD,                   M680x0 ^ M68060},
{OPC_NONE,                  "MOVEP.W", 0x0108, 0xf1f8, MODE_IN_LOWER_BYTE|MODE_AREG_INDIRECT_D16,                                                  MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_DREG_DIRECT,                  OPF_OPERAND_WORD,                   M680x0 ^ M68060},
{OPC_NONE,                  "MOVEP.L", 0x01c8, 0xf1f8, MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_DREG_DIRECT,                                      MODE_IN_LOWER_BYTE|MODE_AREG_INDIRECT_D16,                              OPF_OPERAND_LONG,                   M680x0 ^ M68060},
{OPC_NONE,                  "MOVEP.L", 0x0148, 0xf1f8, MODE_IN_LOWER_BYTE|MODE_AREG_INDIRECT_D16,                                                  MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_DREG_DIRECT,                  OPF_OPERAND_LONG,                   M680x0 ^ M68060},
{OPC_NONE,                  "B",       0x0800, 0xff00, MODE_IN_LOWER_BYTE|MODE_BIT_MANIPULATION,                                                   MODE_NONE,                                                              OPF_NO_FLAG,                        M680x0},
{OPC_NONE,                  "CAS2",    0x08fc, 0xf9ff, MODE_NONE,                                                                                  MODE_IN_LOWER_BYTE|MODE_CAS2,                                           OPF_ONE_MORE_WORD,                  M020UP},
{OPC_NONE,                  "CAS",     0x08c0, 0xf9c0, MODE_IN_LOWER_BYTE|MODE_CAS,                                                                A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,             OPF_ONE_MORE_WORD,                  M020UP},
{OPC_RTM,                   "RTM",     0x06c0, 0xfff0, MODE_NONE,                                                                                  MODE_IN_LOWER_BYTE|MODE_RTM,                                            OPF_NO_FLAG,                        M68020},
{OPC_CALLM,                 "CALLM",   0x06c0, 0xffc0, MODE_IN_LOWER_BYTE|MODE_IMMEDIATE,                                                          A_IND|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND,                    OPF_OPERAND_WORD,                   M68020},
{OPC_C2,                    "C",       0x00c0, 0xf9c0, A_IND|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND,                                        MODE_NONE,                                                              OPF_APPEND_SIZE|OPF_ONE_MORE_WORD,  M020UP},
{OPC_CMPI,                  "CMPI",    0x0c00, 0xff00, MODE_IN_LOWER_BYTE|MODE_IMMEDIATE,                                                          D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,       OPF_APPEND_SIZE,                    M680x0},
{OPC_NONE,                  "EORI",    0x0a00, 0xff00, MODE_IN_LOWER_BYTE|MODE_IMMEDIATE,                                                          D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32|IMMED, OPF_APPEND_SIZE,                    M680x0},
{OPC_NONE,                  "ANDI",    0x0200, 0xff00, MODE_IN_LOWER_BYTE|MODE_IMMEDIATE,                                                          D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32|IMMED, OPF_APPEND_SIZE,                    M680x0},
{OPC_NONE,                  "ADDI",    0x0600, 0xff00, MODE_IN_LOWER_BYTE|MODE_IMMEDIATE,                                                          D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,       OPF_APPEND_SIZE,                    M680x0},
{OPC_NONE,                  "SUBI",    0x0400, 0xff00, MODE_IN_LOWER_BYTE|MODE_IMMEDIATE,                                                          D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,       OPF_APPEND_SIZE,                    M680x0},
{OPC_NONE,                  "ORI",     0x0000, 0xff00, MODE_IN_LOWER_BYTE|MODE_IMMEDIATE,                                                          D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32|IMMED, OPF_APPEND_SIZE,                    M680x0},
{OPC_BITOP,                 "B",       0x0100, 0xf100, MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_BIT_MANIPULATION,                                 MODE_NONE,                                                              OPF_NO_FLAG,                        M680x0},
{OPC_MOVES,                 "MOVES",   0x0e00, 0xff00, MODE_NONE,                                                                                  MODE_NONE,                                                              OPF_APPEND_SIZE|OPF_ONE_MORE_WORD,  M010UP},
{OPC_DBcc,                  "DB",      0x50c8, 0xf0f8, MODE_IN_LOWER_BYTE|MODE_DREG_DIRECT,                                                        MODE_IN_LOWER_BYTE|MODE_DBcc,                                           OPF_OPERAND_BYTE|OPF_APPEND_CC,     M680x0},
{OPC_NONE,                  "TRAP",    0x50fc, 0xf0ff, MODE_NONE,                                                                                  MODE_NONE,                                                              OPF_OPERAND_BYTE|OPF_APPEND_CC,     M020UP},
{OPC_NONE,                  "TRAP",    0x50fa, 0xf0ff, MODE_IN_LOWER_BYTE|MODE_IMMEDIATE,                                                          MODE_NONE,                                                              OPF_OPERAND_WORD|OPF_APPEND_CC,     M020UP},
{OPC_NONE,                  "TRAP",    0x50fb, 0xf0ff, MODE_IN_LOWER_BYTE|MODE_IMMEDIATE,                                                          MODE_NONE,                                                              OPF_OPERAND_LONG|OPF_APPEND_CC,     M020UP},
{OPC_NONE,                  "S",       0x50c0, 0xf0c0, MODE_NONE,                                                                                  D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,       OPF_OPERAND_BYTE|OPF_APPEND_CC,     M680x0},
{OPC_NONE,                  "ADDQ",    0x5000, 0xf100, MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_ADDQ_SUBQ,                                        D_DIR|A_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32, OPF_APPEND_SIZE,                    M680x0},
{OPC_NONE,                  "SUBQ",    0x5100, 0xf100, MODE_IN_LOWER_BYTE|MODE_ALT_REGISTER|MODE_ADDQ_SUBQ,                                        D_DIR|A_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32, OPF_APPEND_SIZE,                    M680x0},
{OPC_Bcc,                   "B",       0x6000, 0xf000, MODE_NONE,                                                                                  MODE_IN_LOWER_BYTE|MODE_Bcc,                                            OPF_OPERAND_BYTE|OPF_APPEND_CC,     M680x0},
{OPC_PMMU,                  "P",       0xf000, 0xffc0, MODE_NONE,                                                                                  MODE_NONE,                                                              OPF_ONE_MORE_WORD,                  M68030|M68851},
{OPC_PFLUSH040,             "PFLUSH",  0xf500, 0xffe0, MODE_NONE,                                                                                  MODE_SPECIFIC,                                                          OPF_NO_FLAG,                        M040UP},
{OPC_PTEST040,              "PTEST",   0xf548, 0xffd8, MODE_IN_LOWER_BYTE|MODE_AREG_INDIRECT,                                                      MODE_NONE,                                                              OPF_NO_FLAG,                        M68040},
{OPC_PBcc,                  "PB",      0xf080, 0xffb0, MODE_NONE,                                                                                  MODE_IN_LOWER_BYTE|MODE_PBcc,                                           OPF_APPEND_SIZE|OPF_APPEND_PCC,     M68851},
{OPC_PDBcc,                 "PDB",     0xf048, 0xfff8, MODE_IN_LOWER_BYTE|MODE_DREG_DIRECT,                                                        MODE_IN_LOWER_BYTE|MODE_PDBcc,                                          OPF_ONE_MORE_WORD|OPF_APPEND_PCC,   M68851},
{OPC_NONE,                  "PSAVE",   0xf100, 0xffc0, MODE_NONE,                                                                                  A_IND|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,                        OPF_NO_FLAG,                        M68851},
{OPC_NONE,                  "PRESTORE",0xf140, 0xffc0, A_IND|A_IND_POST|A_IND_D16|A_IND_IDX|ABS16|ABS32|PC_REL|PC_IND,                             MODE_NONE,                                                              OPF_NO_FLAG,                        M68851},
{OPC_PTRAPcc,               "PTRAP",   0xf078, 0xfff8, MODE_SPECIFIC,                                                                              MODE_NONE,                                                              OPF_ONE_MORE_WORD|OPF_APPEND_PCC,   M68851},
{OPC_PScc,                  "PS",      0xf040, 0xffc0, MODE_NONE,                                                                                  D_DIR|A_IND|A_IND_POST|A_IND_PRE|A_IND_D16|A_IND_IDX|ABS16|ABS32,       OPF_ONE_MORE_WORD|OPF_APPEND_PCC,   M68851},
{OPC_NONE,                  "CINVA",   0xf418, 0xff3f, MODE_IN_LOWER_BYTE|MODE_CACHE_REG,                                                          MODE_NONE,                                                              OPF_NO_FLAG,                        M040UP},
{OPC_CACHE_SCOPE,           "CINV",    0xf400, 0xff20, MODE_IN_LOWER_BYTE|MODE_CACHE_REG,                                                          MODE_IN_LOWER_BYTE|MODE_AREG_INDIRECT,                                  OPF_NO_FLAG,                        M040UP},
{OPC_NONE,                  "CPUSHA",  0xf438, 0xff3f, MODE_IN_LOWER_BYTE|MODE_CACHE_REG,                                                          MODE_NONE,                                                              OPF_NO_FLAG,                        M040UP},
{OPC_CACHE_SCOPE,           "CPUSH",   0xf420, 0xff20, MODE_IN_LOWER_BYTE|MODE_CACHE_REG,                                                          MODE_IN_LOWER_BYTE|MODE_AREG_INDIRECT,                                  OPF_NO_FLAG,                        M040UP},
{OPC_PLPA,                  "PLPA",    0xf588, 0xffb8, MODE_IN_LOWER_BYTE|MODE_AREG_INDIRECT,                                                      MODE_NONE,                                                              OPF_NO_FLAG,                        M68060},
{OPC_MOVE16,                "MOVE16",  0xf620, 0xfff8, MODE_IN_LOWER_BYTE|MODE_AREG_INDIRECT_POST,                                                 MODE_IN_LOWER_BYTE|MODE_AREG_INDIRECT_POST|MODE_EXT_REGISTER,           OPF_ONE_MORE_WORD,                  M040UP},
{OPC_NONE,                  "MOVE16",  0xf600, 0xfff8, MODE_IN_LOWER_BYTE|MODE_AREG_INDIRECT_POST,                                                 MODE_IN_LOWER_BYTE|MODE_ABSOLUTE_32,                                    OPF_NO_FLAG,                        M040UP},
{OPC_NONE,                  "MOVE16",  0xf608, 0xfff8, MODE_IN_LOWER_BYTE|MODE_ABSOLUTE_32,                                                        MODE_IN_LOWER_BYTE|MODE_AREG_INDIRECT_POST,                             OPF_NO_FLAG,                        M040UP},
{OPC_NONE,                  "MOVE16",  0xf610, 0xfff8, MODE_IN_LOWER_BYTE|MODE_AREG_INDIRECT,                                                      MODE_IN_LOWER_BYTE|MODE_ABSOLUTE_32,                                    OPF_NO_FLAG,                        M040UP},
{OPC_NONE,                  "MOVE16",  0xf618, 0xfff8, MODE_IN_LOWER_BYTE|MODE_ABSOLUTE_32,                                                        MODE_IN_LOWER_BYTE|MODE_AREG_INDIRECT,                                  OPF_NO_FLAG,                        M040UP},
{OPC_LPSTOP,                "LPSTOP",  0xf800, 0xffff, MODE_IN_LOWER_BYTE|MODE_IMMEDIATE,                                                          MODE_NONE,                                                              OPF_OPERAND_WORD|OPF_ONE_MORE_WORD, M68060},
/* note: that special opcode description, which stands for "unknown opcode", HAS to be the last element of instructions[] array ! */
{OPC_NONE,                  "",        0x0000, 0x0000, MODE_IN_LOWER_BYTE|MODE_INVALID,                                                            MODE_NONE,                                                              OPF_OPERAND_BYTE,                   M680x0}};

/* instruction (up to 68060) summary */
/*
x  ABCD
x  ADD
x  ADDA
x  ADDI
x  ADDQ
x  ADDX
x  AND
x  ANDI
x  ANDI to CCR
x  ANDI to SR
x  ASL
x  ASR
x  Bcc
x  BCHG
x  BCLR
x  BFCHG
x  BFCLR
x  BFEXTS
x  BFEXTU
x  BFFFO
x  BFINS
x  BFSET
x  BFTST
x  BKPT
x  BRA
x  BSET
x  BSR
x  BTST
x  CALLM
x  CAS
x  CAS2
x  CHK
x  CHK2
x  CINV
x  CLR
x  CMP
x  CMPA
x  CMPI
x  CMPM
x  CMP2
x  CPUSH
x  DBcc
x  DIVS
x  DIVSL
x  DIVU
x  DIVUL
x  EOR
x  EORI
x  EORI to CCR
x  EORI to SR
x  EXG
x  EXT
x  EXTB
   FABS           040 060 88x
   FSABS          040 060
   FDABS          040 060
   FACOS          040 060 88x
   FADD           040 060 88x
   FSADD          040 060
   FDADD          040 060
   FASIN          040 060 88x
   FATAN          040 060 88x
   FATANH         040 060 88x
   FBcc           040 060 88x
   FCMP           040 060 88x
   FCOS           040 060 88x
   FCOSH          040 060 88x
   FDBcc          040 060 88x
   FDIV           040 060 88x
   FSDIV          040 060
   FDDIV          040 060
   FETOX          040 060 88x
   FETOXM1        040 060 88x
   FGETEXP        040 060 88x
   FGETMAN        040 060 88x
   FINT           040 060 88x
   FINTRZ         040 060 88x
   FLOG10         040 060 88x
   FLOG2          040 060 88x
   FLOGN          040 060 88x
   FLOGNP1        040 060
   FMOD           040 060 88x
   FMOVE          040 060 88x
   FSMOVE         040 060
   FDMOVE         040 060
   FMOVECR        040 060 88x
   FMOVEM         040 060 88x
   FMUL           040 060 88x
   FSMUL          040 060
   FDMUL          040 060
   FNEG           040 060 88x
   FSNEG          040 060
   FDNEG          040 060
   FNOP           040 060 88x
   FREM           040 060 88x
   FRESTORE       040 060 88x
   FSAVE          040 060 88x
   FSCALE         040 060 88x
   FScc           040 060 88x
   FSGLDIV        040 060 88x
   FSGLMUL        040 060 88x
   FSIN           040 060 88x
   FSINCOS        040 060 88x
   FSINH          040 060 88x
   FSQRT          040 060 88x
   FSSQRT         040 060
   FDSQRT         040 060
   FSUB           040 060 88x
   FSSUB          040 060
   FDSUB          040 060
   FTAN           040 060 88x
   FTANH          040 060 88x
   FTENTOX        040 060 88x
   FTRAPcc        040 060 88x
   FTST           040 060 88x
   FTWOTOX        040 060 88x
x  ILLEGAL
x  JMP
x  JSR
x  LEA
x  LINK
x  LPSTOP
x  LSL
x  LSR
x  MOVE
x  MOVEA
x  MOVE from CCR
x  MOVE to CCR
x  MOVE from SR
x  MOVE to SR
x  MOVE USP
x  MOVE16
x  MOVEC
x  MOVEM
x  MOVEP
x  MOVEQ
x  MOVES
x  MULS
x  MULU
x  NBCD
x  NEG
x  NEGX
x  NOP
x  NOT
x  OR
x  ORI
x  ORI to CCR
x  ORI to SR
x  PACK
x  PBcc           851
x  PDBcc          851
x  PEA
x  PFLUSH         030 040 060 851
x  PLPA           060
x  PLOAD          030 851
x  PMOVE          030 851
x  PRESTORE       851
x  PSAVE          851
x  PScc           851
x  PTEST          030 040 851
x  PTRAPcc        851
x  PVALID         851
x  RESET
x  ROL
x  ROR
x  ROXL
x  ROXR
x  RTD
x  RTE
x  RTM
x  RTR
x  RTS
x  SBCD
x  Scc
x  STOP
x  SUB
x  SUBA
x  SUBI
x  SUBQ
x  SUBX
x  SWAP
x  TAS
x  TRAP
x  TRAPcc
x  TRAPV
x  TST
x  UNLK
x  UNPK
*/
/* Number of elements in the instructions array above */
const size_t OpCode_number = sizeof(instructions) / sizeof(Opcode_t);

const char cpu_cc[][3] = {"T", "F", "HI", "LS", "CC", "CS", "NE", "EQ", "VC", "VS", "PL", "MI", "GE", "LT", "GT", "LE", "RA", "SR"};
const char mmu_cc[][3] = {"BS", "BC", "LS", "LC", "SS", "SC", "AS", "AC", "WS", "WC", "IS", "IC", "GS", "GC", "CS", "CC"};
const char fpu_cc[][5] = {"F", "EQ", "OGT", "OGE", "OLT", "OLE", "OGL", "OR", "UN", "UEQ", "UGT", "UGE", "ULT", "ULE", "NE", "T", "SF", "SEQ", "GT", "GE", "LT", "LE", "GL", "GLE", "NGLE", "NGL", "NLE", "NLT", "NGE", "NGT", "SNE", "ST"};
const char extensions[][3] = {".B", ".W", ".L"};
const char caches[][3] = {"NC", "DC", "IC", "BC"};
const char bitop[][4] = {"TST", "CHG", "CLR", "SET"};
const char memtypename[][9] = {"PUBLIC", "CHIP", "FAST", "EXTENDED"};
const char modname[][5] = {"CODE", "DATA", "BSS"};
const char bitfield[][5] = {"TST", "EXTU", "CHG", "EXTS", "CLR", "FFO", "SET", "INS"};
const ControlRegister_t ControlRegisters[18] = {
   {"SFC",   M010UP},               {"DFC",  M010UP},               {"CACR",  M020UP}, {"TC",   M040UP},
   {"ITT0",  M040UP},               {"ITT1", M040UP},               {"DTT0",  M040UP}, {"DTT1", M040UP},
   {"BUSCR", M68060},               {"USP",  M010UP},               {"VBR",   M010UP}, {"CAAR", M68020|M68030},
   {"MSP",   M68020|M68030|M68040}, {"ISP",  M68020|M68030|M68040}, {"MMUSR", M68040}, {"URP",  M040UP},
   {"SRP",   M040UP},               {"PCR",  M68060}};
const char pmmu_reg1[][4] = {"TC", "DRP", "SRP", "CRP", "CAL", "VAL", "SCC", "AC"};
const char pmmu_reg2[][5] = {"PSR", "PCSR", "", "", "BAD", "BAC"};

const x_adr_t x_adrs[] = {
{"ABSEXECBASE", 0x0004},
{"BUS_ERROR",   0x0008},
{"ADR_ERROR",   0x000C},
{"ILLEG_OPC",   0x0010},
{"DIVISION0",   0x0014},
{"CHK",         0x0018},
{"TRAPV",       0x001C},
{"PRIVILEG",    0x0020},
{"TRACE",       0x0024},
{"LINEA_EMU",   0x0028},
{"LINEF_EMU",   0x002C},
{"INT_NOINI",   0x003C},
{"INT_WRONG",   0x0060},
{"AUTO_INT1",   0x0064},
{"AUTO_INT2",   0x0068},
{"AUTO_INT3",   0x006C},
{"AUTO_INT4",   0x0070},
{"AUTO_INT5",   0x0074},
{"AUTO_INT6",   0x0078},
{"NMI",         0x007C},
{"TRAP_01",     0x0080},
{"TRAP_02",     0x0084},
{"TRAP_03",     0x0088},
{"TRAP_04",     0x008C},
{"TRAP_05",     0x0090},
{"TRAP_06",     0x0094},
{"TRAP_07",     0x0098},
{"TRAP_08",     0x009C},
{"TRAP_09",     0x00A0},
{"TRAP_10",     0x00A4},
{"TRAP_11",     0x00A8},
{"TRAP_12",     0x00AC},
{"TRAP_13",     0x00B0},
{"TRAP_14",     0x00B4},
{"TRAP_15",     0x00B8},
{"CIAB_PRA",    0xBFD000},
{"CIAB_PRB",    0xBFD100},
{"CIAB_DDRA",   0xBFD200},
{"CIAB_DDRB",   0xBFD300},
{"CIAB_TALO",   0xBFD400},
{"CIAB_TAHI",   0xBFD500},
{"CIAB_TBLO",   0xBFD600},
{"CIAB_TBHI",   0xBFD700},
{"CIAB_TDLO",   0xBFD800},
{"CIAB_TDMD",   0xBFD900},
{"CIAB_TDHI",   0xBFDA00},
{"CIAB_SDR",    0xBFDC00},
{"CIAB_ICR",    0xBFDD00},
{"CIAB_CRA",    0xBFDE00},
{"CIAB_CRB",    0xBFDF00},
{"CIAA_PRA",    0xBFE001},
{"CIAA_PRB",    0xBFE101},
{"CIAA_DDRA",   0xBFE201},
{"CIAA_DDRB",   0xBFE301},
{"CIAA_TALO",   0xBFE401},
{"CIAA_TAHI",   0xBFE501},
{"CIAA_TBLO",   0xBFE601},
{"CIAA_TBHI",   0xBFE701},
{"CIAA_TDLO",   0xBFE801},
{"CIAA_TDMD",   0xBFE901},
{"CIAA_TDHI",   0xBFEA01},
{"CIAA_SDR",    0xBFEC01},
{"CIAA_ICR",    0xBFED01},
{"CIAA_CRA",    0xBFEE01},
{"CIAA_CRB",    0xBFEF01},
{"CLK_S1",      0xDC0000},
{"CLK_S10",     0xDC0004},
{"CLK_MI1",     0xDC0008},
{"CLK_MI10",    0xDC000C},
{"CLK_H1",      0xDC0010},
{"CLK_H10",     0xDC0014},
{"CLK_D1",      0xDC0018},
{"CLK_D10",     0xDC001C},
{"CLK_MO1",     0xDC0020},
{"CLK_MO10",    0xDC0024},
{"CLK_Y1",      0xDC0028},
{"CLK_Y10",     0xDC002E},
{"CLK_WEEK",    0xDC0030},
{"CLK_CD",      0xDC0034},
{"CLK_CE",      0xDC0038},
{"CLK_CF",      0xDC003C},
{"HARDBASE",    0xDFF000},
{"DMACONR",     0xDFF002},
{"VPOSR",       0xDFF004},
{"VHPOSR",      0xDFF006},
{"DSKDATR",     0xDFF008},
{"JOY0DAT",     0xDFF00A},
{"JOY1DAT",     0xDFF00C},
{"CLXDAT",      0xDFF00E},
{"ADKCONR",     0xDFF010},
{"POT0DAT",     0xDFF012},
{"POT1DAT",     0xDFF014},
{"POTGOR",      0xDFF016},
{"SERDATR",     0xDFF018},
{"DSKBYTR",     0xDFF01A},
{"INTENAR",     0xDFF01C},
{"INTREQR",     0xDFF01E},
{"DSKPTH",      0xDFF020},
{"DSKPTL",      0xDFF022},
{"DSKLEN",      0xDFF024},
{"DSKDAT",      0xDFF026},
{"REFPTR",      0xDFF028},
{"VPOSW",       0xDFF02A},
{"VHPOSW",      0xDFF02C},
{"COPCON",      0xDFF02E},
{"SERDAT",      0xDFF030},
{"SERPER",      0xDFF032},
{"POTGO",       0xDFF034},
{"JOYTEST",     0xDFF036},
{"STREQU",      0xDFF038},
{"STRVBL",      0xDFF03A},
{"STRHOR",      0xDFF03C},
{"STRLONG",     0xDFF03E},
{"BLTCON0",     0xDFF040},
{"BLTCON1",     0xDFF042},
{"BLTAFWM",     0xDFF044},
{"BLTALWM",     0xDFF046},
{"BLTCPTH",     0xDFF048},
{"BLTCPTL",     0xDFF04A},
{"BLTBPTH",     0xDFF04C},
{"BLTBPTL",     0xDFF04E},
{"BLTAPTH",     0xDFF050},
{"BLTAPTL",     0xDFF052},
{"BLTDPTH",     0xDFF054},
{"BLTDPTL",     0xDFF056},
{"BLTSIZE",     0xDFF058},
{"BLTCON01",    0xDFF05A}, /* ECS */
{"BLTSIZV",     0xDFF05C}, /* ECS */
{"BLTSIZH",     0xDFF05E}, /* ECS */
{"BLTCMOD",     0xDFF060},
{"BLTBMOD",     0xDFF062},
{"BLTAMOD",     0xDFF064},
{"BLTDMOD",     0xDFF066}, /* 50 */
{"BLTCDAT",     0xDFF070},
{"BLTBDAT",     0xDFF072},
{"BLTADAT",     0xDFF074},
{"BLTDDAT",     0xDFF076},
{"SPRHDAT",     0xDFF078}, /* ECS */
{"DENISEID",    0xDFF07C}, /* ECS */
{"DSKSYNC",     0xDFF07E},
{"COP1LCH",     0xDFF080},
{"COP1LCL",     0xDFF082},
{"COP2LCH",     0xDFF084},
{"COP2LCL",     0xDFF086},
{"COPJMP1",     0xDFF088},
{"COPJMP2",     0xDFF08A},
{"COPINS",      0xDFF08C},
{"DIWSTRT",     0xDFF08E},
{"DIWSTOP",     0xDFF090},
{"DDFSTRT",     0xDFF092},
{"DFFSTOP",     0xDFF094},
{"DMACON",      0xDFF096},
{"CLXCON",      0xDFF098},
{"INTENA",      0xDFF09A},
{"INTREQ",      0xDFF09C},
{"ADKCON",      0xDFF09E},
{"AUD0LCH",     0xDFF0A0},
{"AUD0LCL",     0xDFF0A2},
{"AUD0LEN",     0xDFF0A4},
{"AUD0PER",     0xDFF0A6},
{"AUD0VOL",     0xDFF0A8},
{"AUD0DAT",     0xDFF0AA},
{"AUD1LCH",     0xDFF0B0},
{"AUD1LCL",     0xDFF0B2},
{"AUD1LEN",     0xDFF0B4},
{"AUD1PER",     0xDFF0B6},
{"AUD1VOL",     0xDFF0B8},
{"AUD1DAT",     0xDFF0BA},
{"AUD2LCH",     0xDFF0C0},
{"AUD2LCL",     0xDFF0C2},
{"AUD2LEN",     0xDFF0C4},
{"AUD2PER",     0xDFF0C6},
{"AUD2VOL",     0xDFF0C8},
{"AUD2DAT",     0xDFF0CA},
{"AUD3LCH",     0xDFF0D0},
{"AUD3LCL",     0xDFF0D2},
{"AUD3LEN",     0xDFF0D4},
{"AUD3PER",     0xDFF0D6},
{"AUD3VOL",     0xDFF0D8},
{"AUD3DAT",     0xDFF0DA},
{"BPL1PTH",     0xDFF0E0},
{"BPL1PTL",     0xDFF0E2},
{"BPL2PTH",     0xDFF0E4},
{"BPL2PTL",     0xDFF0E6},
{"BPL3PTH",     0xDFF0E8},
{"BPL3PTL",     0xDFF0EA},
{"BPL4PTH",     0xDFF0EC},
{"BPL4PTL",     0xDFF0EE},
{"BPL5PTH",     0xDFF0F0},
{"BPL5PTL",     0xDFF0F2},
{"BPL6PTH",     0xDFF0F4},
{"BPL6PTL",     0xDFF0F6},
{"BPLCON0",     0xDFF100},
{"BPLCON1",     0xDFF102},
{"BPLCON2",     0xDFF104},
{"BPLCON3",     0xDFF106}, /* ECS */
{"BPL1MOD",     0xDFF108},
{"BPL2MOD",     0xDFF10A},
{"BPL1DAT",     0xDFF110},
{"BPL2DAT",     0xDFF112},
{"BPL3DAT",     0xDFF114},
{"BPL4DAT",     0xDFF116},
{"BPL5DAT",     0xDFF118},
{"BPL6DAT",     0xDFF11A},
{"SPR0PTH",     0xDFF120},
{"SPR0PTL",     0xDFF122},
{"SPR1PTH",     0xDFF124},
{"SPR1PTL",     0xDFF126},
{"SPR2PTH",     0xDFF128},
{"SPR2PTL",     0xDFF12A},
{"SPR3PTH",     0xDFF12C},
{"SPR3PTL",     0xDFF12E},
{"SPR4PTH",     0xDFF130},
{"SPR4PTL",     0xDFF132},
{"SPR5PTH",     0xDFF134},
{"SPR5PTL",     0xDFF136},
{"SPR6PTH",     0xDFF138},
{"SPR6PTL",     0xDFF13A},
{"SPR7PTH",     0xDFF13C},
{"SPR7PTL",     0xDFF13E},
{"SPR0POS",     0xDFF140},
{"SPR0CTL",     0xDFF142},
{"SPR0DATA",    0xDFF144},
{"SPR0DATB",    0xDFF146},
{"SPR1POS",     0xDFF148},
{"SPR1CTL",     0xDFF14A},
{"SPR1DATA",    0xDFF14C},
{"SPR1DATB",    0xDFF14E},
{"SPR2POS",     0xDFF150},
{"SPR2CTL",     0xDFF152},
{"SPR2DATA",    0xDFF154},
{"SPR2DATB",    0xDFF156},
{"SPR3POS",     0xDFF158},
{"SPR3CTL",     0xDFF15A},
{"SPR3DATA",    0xDFF15C},
{"SPR3DATB",    0xDFF15E},
{"SPR4POS",     0xDFF160},
{"SPR4CTL",     0xDFF162},
{"SPR4DATA",    0xDFF164},
{"SPR4DATB",    0xDFF166},
{"SPR5POS",     0xDFF168},
{"SPR5CTL",     0xDFF16A},
{"SPR5DATA",    0xDFF16C},
{"SPR5DATB",    0xDFF16E},
{"SPR6POS",     0xDFF170},
{"SPR6CTL",     0xDFF172},
{"SPR6DATA",    0xDFF174},
{"SPR6DATB",    0xDFF176},
{"SPR7POS",     0xDFF178},
{"SPR7CTL",     0xDFF17A},
{"SPR7DATA",    0xDFF17C},
{"SPR7DATB",    0xDFF17E},
{"COLOR00",     0xDFF180},
{"COLOR01",     0xDFF182},
{"COLOR02",     0xDFF184},
{"COLOR03",     0xDFF186},
{"COLOR04",     0xDFF188},
{"COLOR05",     0xDFF18A},
{"COLOR06",     0xDFF18C},
{"COLOR07",     0xDFF18E},
{"COLOR08",     0xDFF190},
{"COLOR09",     0xDFF192},
{"COLOR10",     0xDFF194},
{"COLOR11",     0xDFF196},
{"COLOR12",     0xDFF198},
{"COLOR13",     0xDFF19A},
{"COLOR14",     0xDFF19C},
{"COLOR15",     0xDFF19E},
{"COLOR16",     0xDFF1A0},
{"COLOR17",     0xDFF1A2},
{"COLOR18",     0xDFF1A4},
{"COLOR19",     0xDFF1A6},
{"COLOR20",     0xDFF1A8},
{"COLOR21",     0xDFF1AA},
{"COLOR22",     0xDFF1AC},
{"COLOR23",     0xDFF1AE},
{"COLOR24",     0xDFF1B0},
{"COLOR25",     0xDFF1B2},
{"COLOR26",     0xDFF1B4},
{"COLOR27",     0xDFF1B6},
{"COLOR28",     0xDFF1B8},
{"COLOR29",     0xDFF1BA},
{"COLOR30",     0xDFF1BC},
{"COLOR31",     0xDFF1BE},
{"HTOTAL",      0xDFF1C0}, /* Starting here, only ECS-Register */
{"HSSTOP",      0xDFF1C2},
{"HBSTRT",      0xDFF1C4},
{"HBSTOP",      0xDFF1C6},
{"VTOTAL",      0xDFF1C8},
{"VSSTOP",      0xDFF1CA},
{"VBSTRT",      0xDFF1CC},
{"VBSTOP",      0xDFF1CE},
{"SPRHSTRT",    0xDFF1D0},
{"SPRHSTOP",    0xDFF1D2},
{"BPLHSTRT",    0xDFF1D4},
{"BPLHSTOP",    0xDFF1D6},
{"HHPOSW",      0xDFF1D8},
{"HHPOSR",      0xDFF1DA},
{"BEAMCON0",    0xDFF1DC},
{"HSSTRT",      0xDFF1DE},
{"VSSTRT",      0xDFF1E0},
{"HCENTER",     0xDFF1E2},
{"DIWHIGH",     0xDFF1E4},
{"BPLHMOD",     0xDFF1E6},
{"SPRHPTH",     0xDFF1E8},
{"SPRHPTL",     0xDFF1EA},
{"BPLHPTH",     0xDFF1EC},
{"BPLHPTL",     0xDFF1EE},
{"FMODE",       0xDFF1FE}};

/* Number of elements in the x_adrs array above */
const size_t x_adr_number = sizeof(x_adrs) / sizeof(x_adr_t);
