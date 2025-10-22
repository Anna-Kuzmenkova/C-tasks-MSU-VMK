ANSWERS
***Answer 29:
aplusb.c:1:6: error: return type of ‘main’ is not ‘int’ [-Werror=main]
    1 | void main()
      |      ^~~~
aplusb.c: In function ‘main’:
aplusb.c:4:1: error: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
    4 | scanf("%d%d", a, &b);
      | ^~~~~
aplusb.c:1:1: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
  +++ |+#include <stdio.h>
    1 | void main()
aplusb.c:4:1: error: incompatible implicit declaration of built-in function ‘scanf’ [-Werror=builtin-declaration-mismatch]
    4 | scanf("%d%d", a, &b);
      | ^~~~~
aplusb.c:4:1: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
aplusb.c:4:9: error: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘int’ [-Werror=format=]
    4 | scanf("%d%d", a, &b);
      |        ~^     ~
      |         |     |
      |         int * int
aplusb.c:5:3: error: statement with no effect [-Werror=unused-value]
    5 | c == a + b;
      | ~~^~~~~~~~
aplusb.c:6:1: error: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
    6 | printf("%d\n", c);
      | ^~~~~~
aplusb.c:6:1: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
aplusb.c:6:1: error: incompatible implicit declaration of built-in function ‘printf’ [-Werror=builtin-declaration-mismatch]
aplusb.c:6:1: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
cc1: all warnings being treated as errors
***Answer 30:
-rwxr-xr-x 1 s02230160 s02230160 12584 Sep 12 19:19 aplusb
***Answer 31:
13755
***Answer 32:
./aplusb < 001.dat > 001.res
***Answer 33:
29287
***Answer 34:
0m0.001s
***Answer 35:
350000000
***Answer 36:
команда выведет на экран список текущих процессов, в имени которых есть sh
1 I     0       7       2  0  60 -20 -     0 -      ?        00:00:00 kworker/R-slub_flushwq
4 S     0     820       1  0  80   0 -  2051 -      ?        00:00:07 sshd
0 S  1299    9957    9956  0  80   0 -  2973 -      pts/13   00:00:00 bash
0 S  1299    9980    9956  0  80   0 -  3006 -      pts/14   00:00:00 bash
4 S     0   19306     820  0  80   0 -  3824 -      ?        00:00:00 sshd-session
5 S  1226   19334   19306  0  80   0 -  3928 -      ?        00:00:05 sshd-session
0 S  1226   19335   19334  0  80   0 -  2991 -      pts/7    00:00:00 bash
4 S     0   19901     820  0  80   0 -  3789 -      ?        00:00:00 sshd-session
5 S  1174   19904   19901  0  80   0 -  3899 -      ?        00:00:00 sshd-session
0 S  1174   19905   19904  0  80   0 -  2992 -      pts/2    00:00:00 bash
4 S     0   21771     820  0  80   0 -  3824 -      ?        00:00:00 sshd-session
5 S  1275   21775   21771  0  80   0 -  3889 -      ?        00:00:00 sshd-session
0 S  1275   21776   21775  0  80   0 -  2959 -      pts/9    00:00:00 bash
4 S     0   21852     820  0  80   0 -  3824 -      ?        00:00:00 sshd-session
5 S  1275   21856   21852  0  80   0 -  3889 -      ?        00:00:00 sshd-session
0 S  1275   21857   21856  0  80   0 -  2959 -      pts/0    00:00:00 bash
4 S     0   21887     820  0  80   0 -  3824 -      ?        00:00:00 sshd-session
5 S  1251   21904   21887  0  80   0 -  3889 -      ?        00:00:00 sshd-session
0 S  1251   21905   21904  0  80   0 -  2959 -      pts/10   00:00:00 bash
4 S     0   22126     820  0  80   0 -  3824 -      ?        00:00:00 sshd-session
5 S  1182   22145   22126  0  80   0 -  3889 -      ?        00:00:00 sshd-session
0 S  1182   22146   22145  0  80   0 -  2959 -      pts/15   00:00:00 bash
4 S     0   22299     820  0  80   0 -  3789 -      ?        00:00:00 sshd-session
5 S  1259   22303   22299  0  80   0 -  3854 -      ?        00:00:00 sshd-session
0 S  1259   22304   22303  0  80   0 -  2991 -      pts/12   00:00:00 bash
4 S     0   22354     820  0  80   0 -  3824 -      ?        00:00:00 sshd-session
5 S  1251   22359   22354  0  80   0 -  3889 -      ?        00:00:00 sshd-session
0 S  1251   22360   22359  0  80   0 -  2959 -      pts/18   00:00:00 bash
4 S     0   22704     820  0  80   0 -  3830 -      ?        00:00:00 sshd-session
5 S  1285   22763   22704  0  80   0 -  3914 -      ?        00:00:00 sshd-session
0 S  1285   22764   22763  0  80   0 -  2992 -      pts/19   00:00:00 bash
4 S     0   23586     820  0  80   0 -  3824 -      ?        00:00:00 sshd-session
5 S  1251   23591   23586  0  80   0 -  3889 -      ?        00:00:00 sshd-session
0 S  1251   23592   23591  0  80   0 -  2959 -      pts/6    00:00:00 bash
4 S     0   24271     820  0  80   0 -  3789 -      ?        00:00:00 sshd-session
5 S  1182   24274   24271  0  80   0 -  3854 -      ?        00:00:00 sshd-session
0 S  1182   24275   24274  0  80   0 -  2959 -      pts/23   00:00:00 bash
1 I     0   24562       2  0  80   0 -     0 -      ?        00:00:00 kworker/u8:3-flush-253:0
4 S     0   26010     820  0  80   0 -  3790 -      ?        00:00:00 sshd-session
5 S  1302   26044   26010  0  80   0 -  3855 -      ?        00:00:00 sshd-session
0 S  1302   26045   26044  0  80   0 -  2990 -      pts/4    00:00:00 bash
4 S     0   26091     820  0  80   0 -  3790 -      ?        00:00:00 sshd-session
5 S  1302   26094   26091  0  80   0 -  3855 -      ?        00:00:00 sshd-session
0 S  1302   26095   26094  0  80   0 -  2959 -      pts/11   00:00:00 bash
4 S     0   26130     820  0  80   0 -  3856 -      ?        00:00:00 sshd-session
5 S  1171   26134   26130  0  80   0 -  3856 -      ?        00:00:00 sshd-session
0 S  1171   26135   26134  0  80   0 -  2992 do_wai pts/16   00:00:00 bash
4 S     0   26236     820  0  80   0 -  3829 -      ?        00:00:00 sshd-session
5 S  1285   26246   26236  0  80   0 -  3967 -      ?        00:00:00 sshd-session
0 S  1285   26247   26246  0  80   0 -  2992 -      pts/20   00:00:00 bash
4 S     0   26496     820  0  80   0 -  3789 -      ?        00:00:00 sshd-session
5 S  1292   26516   26496  0  80   0 -  3862 -      ?        00:00:00 sshd-session
0 S  1292   26517   26516  0  80   0 -  2959 -      pts/5    00:00:00 bash
4 S     0   26796     820  0  80   0 -  3826 -      ?        00:00:00 sshd-session
5 S  1227   26818   26796  0  80   0 -  3891 -      ?        00:00:00 sshd-session
0 S  1227   26819   26818  0  80   0 -  3533 -      pts/1    00:00:00 bash
4 S     0   26893     820  0  80   0 -  3789 -      ?        00:00:00 sshd-session
5 S  1174   26896   26893  0  80   0 -  3862 -      ?        00:00:00 sshd-session
0 S  1174   26897   26896  0  80   0 -  2992 -      pts/3    00:00:00 bash
4 S     0   27044     820  0  80   0 -  3789 -      ?        00:00:00 sshd-session
5 S  1292   27047   27044  0  80   0 -  3880 -      ?        00:00:00 sshd-session
0 S  1292   27048   27047  0  80   0 -  2959 -      pts/8    00:00:00 bash
***Answer 37:
При внештатном завершении программы создается core dump - файл с адресным пространством процесса в момент завершения. 
ulimit -c показывает текущее ограничение на размер core dump-файла. При запуске выводит unlimited, значит разрешено создавать core dump-файлы любого размера. 
ulimit -c 0 устанавливает разрешенный размер 0, то есть запрещает создавать core dump-файлы
***Answer 38:
There are 36 section headers, starting at offset 0x2b48:

Section Headers:
  [Nr] Name              Type             Address           Offset
       Size              EntSize          Flags  Link  Info  Align
  [ 0]                   NULL             0000000000000000  00000000
       0000000000000000  0000000000000000           0     0     0
  [ 1] .note.gnu.bu[...] NOTE             0000000000400318  00000318
       0000000000000024  0000000000000000   A       0     0     4
  [ 2] .init             PROGBITS         000000000040033c  0000033c
       000000000000001b  0000000000000000  AX       0     0     4
  [ 3] .text             PROGBITS         0000000000400360  00000360
       0000000000000103  0000000000000000  AX       0     0     16
  [ 4] .fini             PROGBITS         0000000000400464  00000464
       000000000000000d  0000000000000000  AX       0     0     4
  [ 5] .interp           PROGBITS         0000000000401000  00001000
       000000000000001c  0000000000000000   A       0     0     1
  [ 6] .gnu.hash         GNU_HASH         0000000000401020  00001020
       000000000000001c  0000000000000000   A       7     0     8
  [ 7] .dynsym           DYNSYM           0000000000401040  00001040
       0000000000000048  0000000000000018   A       8     1     8
  [ 8] .dynstr           STRTAB           0000000000401088  00001088
       0000000000000037  0000000000000000   A       0     0     1
  [ 9] .gnu.version      VERSYM           00000000004010c0  000010c0
       0000000000000006  0000000000000002   A       7     0     2
  [10] .gnu.version_r    VERNEED          00000000004010c8  000010c8
       0000000000000020  0000000000000000   A       8     1     8
  [11] .rela.dyn         RELA             00000000004010e8  000010e8
       0000000000000030  0000000000000018   A       7     0     8
  [12] .rodata           PROGBITS         0000000000401118  00001118
       0000000000000010  0000000000000000   A       0     0     8
  [13] .eh_frame_hdr     PROGBITS         0000000000401128  00001128
       0000000000000024  0000000000000000   A       0     0     4
  [14] .eh_frame         PROGBITS         0000000000401150  00001150
       0000000000000064  0000000000000000   A       0     0     8
  [15] .note.gnu.pr[...] NOTE             00000000004011b8  000011b8
       0000000000000040  0000000000000000   A       0     0     8
  [16] .note.ABI-tag     NOTE             00000000004011f8  000011f8
       0000000000000020  0000000000000000   A       0     0     4
  [17] .init_array       INIT_ARRAY       0000000000402e38  00001e38
       0000000000000008  0000000000000008  WA       0     0     8
  [18] .fini_array       FINI_ARRAY       0000000000402e40  00001e40
       0000000000000008  0000000000000008  WA       0     0     8
  [19] .dynamic          DYNAMIC          0000000000402e48  00001e48
       0000000000000190  0000000000000010  WA       8     0     8
  [20] .got              PROGBITS         0000000000402fd8  00001fd8
       0000000000000010  0000000000000008  WA       0     0     8
  [21] .got.plt          PROGBITS         0000000000402fe8  00001fe8
       0000000000000018  0000000000000008  WA       0     0     8
  [22] .data             PROGBITS         0000000000403000  00002000
       0000000000000004  0000000000000000  WA       0     0     1
  [23] .bss              NOBITS           0000000000403004  00002004
       0000000000000004  0000000000000000  WA       0     0     1
  [24] .comment          PROGBITS         0000000000000000  00002004
       000000000000002e  0000000000000001  MS       0     0     1
  [25] .annobin.notes    PROGBITS         0000000000000000  00002032
       000000000000014f  0000000000000001  MS       0     0     1
  [26] .gnu.build.a[...] NOTE             0000000000405008  00002184
       0000000000000144  0000000000000000           0     0     4
  [27] .debug_aranges    PROGBITS         0000000000000000  000022c8
       0000000000000030  0000000000000000           0     0     1
  [28] .debug_info       PROGBITS         0000000000000000  000022f8
       00000000000000a9  0000000000000000           0     0     1
  [29] .debug_abbrev     PROGBITS         0000000000000000  000023a1
       0000000000000067  0000000000000000           0     0     1
  [30] .debug_line       PROGBITS         0000000000000000  00002408
       0000000000000055  0000000000000000           0     0     1
  [31] .debug_str        PROGBITS         0000000000000000  0000245d
       0000000000000096  0000000000000001  MS       0     0     1
  [32] .debug_line_str   PROGBITS         0000000000000000  000024f3
       0000000000000019  0000000000000001  MS       0     0     1
  [33] .symtab           SYMTAB           0000000000000000  00002510
       0000000000000318  0000000000000018          34    18     8
  [34] .strtab           STRTAB           0000000000000000  00002828
       000000000000019a  0000000000000000           0     0     1
  [35] .shstrtab         STRTAB           0000000000000000  000029c2
       0000000000000181  0000000000000000           0     0     1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings), I (info),
  L (link order), O (extra OS processing required), G (group), T (TLS),
  C (compressed), x (unknown), o (OS specific), E (exclude),
  D (mbind), l (large), p (processor specific)
***Answer 39:
ls -lSr /etc/*.conf | head -n 5 
***Answer 40:
grep -v '[aeiou]' /usr/share/dict/words | wc -w
