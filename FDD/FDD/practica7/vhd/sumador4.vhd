
--  CYPRESS NOVA XVL Structural Architecture

--  JED2VHD Reverse Assembler - 6.3 IR 35


--    VHDL File: sumador4.vhd

--    Date: Wed Oct 09 10:26:30 2019

--  Disassembly from Jedec file for: c22v10

--  Device Ordercode is: PALCE22V10-15PC
library ieee;
use ieee.std_logic_1164.all;

library primitive;
use primitive.primitive.all;


-- Beginning Test Bench Header

ENTITY suma IS
    PORT (
	                  c0 :    in std_logic ;
	                  a1 :    in std_logic ;
	                  a2 :    in std_logic ;
	                  a3 :    in std_logic ;
	                  a4 :    in std_logic ;
	                  b1 :    in std_logic ;
	                  b2 :    in std_logic ;
	                  b3 :    in std_logic ;
	                  b4 :    in std_logic ;
	                  s1 : inout std_logic ;
	                  s2 : inout std_logic ;
	                  s3 : inout std_logic ;
	                  c1 : inout std_logic ;
	                  c2 : inout std_logic ;
	                  c3 : inout std_logic ;
	                  c4 : inout std_logic
    );
END suma;

-- End of Test Bench Header

ARCHITECTURE DSMB of suma is

	signal jed_node1	: std_logic:='0' ; -- b4
	signal jed_node2	: std_logic:='0' ; -- a4
	signal jed_node3	: std_logic:='0' ; -- b3
	signal jed_node4	: std_logic:='0' ; -- b2
	signal jed_node5	: std_logic:='0' ; -- b1
	signal jed_node6	: std_logic:='0' ; -- a3
	signal jed_node7	: std_logic:='0' ; -- a2
	signal jed_node8	: std_logic:='0' ; -- a1
	signal jed_node9	: std_logic:='0' ;
	signal jed_node10	: std_logic:='0' ;
	signal jed_node11	: std_logic:='0' ;
	signal jed_node12	: std_logic:='0' ;
	signal jed_node13	: std_logic:='0' ;
	signal jed_node17	: std_logic:='0' ;
	signal jed_node20	: std_logic:='0' ;
	signal jed_node21	: std_logic:='0' ; -- c0
	signal jed_node24	: std_logic:='0' ;

	for all: c22v10m use entity primitive.c22v10m (sim);

SIGNAL  one:std_logic:='1';
SIGNAL  zero:std_logic:='0';
SIGNAL  jed_oept_1:std_logic:='0';
--Attribute PIN_NUMBERS of b4:SIGNAL is "0001";

SIGNAL  jed_oept_2:std_logic:='0';
--Attribute PIN_NUMBERS of a4:SIGNAL is "0002";

SIGNAL  jed_oept_3:std_logic:='0';
--Attribute PIN_NUMBERS of b3:SIGNAL is "0003";

SIGNAL  jed_oept_4:std_logic:='0';
--Attribute PIN_NUMBERS of b2:SIGNAL is "0004";

SIGNAL  jed_oept_5:std_logic:='0';
--Attribute PIN_NUMBERS of b1:SIGNAL is "0005";

SIGNAL  jed_oept_6:std_logic:='0';
--Attribute PIN_NUMBERS of a3:SIGNAL is "0006";

SIGNAL  jed_oept_7:std_logic:='0';
--Attribute PIN_NUMBERS of a2:SIGNAL is "0007";

SIGNAL  jed_oept_8:std_logic:='0';
--Attribute PIN_NUMBERS of a1:SIGNAL is "0008";

SIGNAL  jed_oept_14:std_logic:='0';
SIGNAL  jed_sum_14,jed_fb_14:std_logic:='0';
--Attribute PIN_NUMBERS of c3:SIGNAL is "0014";

SIGNAL  jed_oept_15:std_logic:='0';
SIGNAL  jed_sum_15,jed_fb_15:std_logic:='0';
--Attribute PIN_NUMBERS of c2:SIGNAL is "0015";

SIGNAL  jed_oept_16:std_logic:='0';
SIGNAL  jed_sum_16,jed_fb_16:std_logic:='0';
--Attribute PIN_NUMBERS of c1:SIGNAL is "0016";

SIGNAL  jed_oept_18:std_logic:='0';
SIGNAL  jed_sum_18,jed_fb_18:std_logic:='0';
--Attribute PIN_NUMBERS of s3:SIGNAL is "0018";

SIGNAL  jed_oept_19:std_logic:='0';
SIGNAL  jed_sum_19,jed_fb_19:std_logic:='0';
--Attribute PIN_NUMBERS of c4:SIGNAL is "0019";

SIGNAL  jed_oept_21:std_logic:='0';
SIGNAL  jed_sum_21,jed_fb_21:std_logic:='0';
--Attribute PIN_NUMBERS of c0:SIGNAL is "0021";

SIGNAL  jed_oept_22:std_logic:='0';
SIGNAL  jed_sum_22,jed_fb_22:std_logic:='0';
--Attribute PIN_NUMBERS of s1:SIGNAL is "0022";

SIGNAL  jed_oept_23:std_logic:='0';
SIGNAL  jed_sum_23,jed_fb_23:std_logic:='0';
--Attribute PIN_NUMBERS of s2:SIGNAL is "0023";

SIGNAL  jed_oept_25:std_logic:='0';
SIGNAL  jed_node25,jed_sum_25:std_logic:='0';
SIGNAL  jed_oept_26:std_logic:='0';
SIGNAL  jed_node26,jed_sum_26:std_logic:='0';

BEGIN
jed_node1 <= b4 ;
jed_node2 <= a4 ;
jed_node3 <= b3 ;
jed_node4 <= b2 ;
jed_node5 <= b1 ;
jed_node6 <= a3 ;
jed_node7 <= a2 ;
jed_node8 <= a1 ;
jed_node21 <= c0 ;
Mcell_14:c22v10m
generic map(comb,
   ninv,
   xpin,
   	15 ns, --tpd
	15 ns, --tea
	15 ns, --ter
	8 ns, --tco
	10 ns, --ts
	0 ns, --th
	6 ns, --twh
	6 ns, --twl
	4 ns, --tcf
	15 ns, --taw
	12 ns, --tar
	20 ns, --tap
	20 ns  --tspr
)
port map(
     d=>jed_sum_14,
     clk=>jed_node1,
     oe=>jed_oept_14,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>c3,
     fb=>jed_fb_14
   );

Mcell_15:c22v10m
generic map(comb,
   ninv,
   xpin,
   	15 ns, --tpd
	15 ns, --tea
	15 ns, --ter
	8 ns, --tco
	10 ns, --ts
	0 ns, --th
	6 ns, --twh
	6 ns, --twl
	4 ns, --tcf
	15 ns, --taw
	12 ns, --tar
	20 ns, --tap
	20 ns  --tspr
)
port map(
     d=>jed_sum_15,
     clk=>jed_node1,
     oe=>jed_oept_15,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>c2,
     fb=>jed_fb_15
   );

Mcell_16:c22v10m
generic map(comb,
   ninv,
   xpin,
   	15 ns, --tpd
	15 ns, --tea
	15 ns, --ter
	8 ns, --tco
	10 ns, --ts
	0 ns, --th
	6 ns, --twh
	6 ns, --twl
	4 ns, --tcf
	15 ns, --taw
	12 ns, --tar
	20 ns, --tap
	20 ns  --tspr
)
port map(
     d=>jed_sum_16,
     clk=>jed_node1,
     oe=>jed_oept_16,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>c1,
     fb=>jed_fb_16
   );

Mcell_18:c22v10m
generic map(comb,
   ninv,
   xpin,
   	15 ns, --tpd
	15 ns, --tea
	15 ns, --ter
	8 ns, --tco
	10 ns, --ts
	0 ns, --th
	6 ns, --twh
	6 ns, --twl
	4 ns, --tcf
	15 ns, --taw
	12 ns, --tar
	20 ns, --tap
	20 ns  --tspr
)
port map(
     d=>jed_sum_18,
     clk=>jed_node1,
     oe=>jed_oept_18,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>s3,
     fb=>jed_fb_18
   );

Mcell_19:c22v10m
generic map(comb,
   ninv,
   xpin,
   	15 ns, --tpd
	15 ns, --tea
	15 ns, --ter
	8 ns, --tco
	10 ns, --ts
	0 ns, --th
	6 ns, --twh
	6 ns, --twl
	4 ns, --tcf
	15 ns, --taw
	12 ns, --tar
	20 ns, --tap
	20 ns  --tspr
)
port map(
     d=>jed_sum_19,
     clk=>jed_node1,
     oe=>jed_oept_19,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>c4,
     fb=>jed_fb_19
   );

Mcell_21:c22v10m
generic map(comb,
   ninv,
   xpin,
   	15 ns, --tpd
	15 ns, --tea
	15 ns, --ter
	8 ns, --tco
	10 ns, --ts
	0 ns, --th
	6 ns, --twh
	6 ns, --twl
	4 ns, --tcf
	15 ns, --taw
	12 ns, --tar
	20 ns, --tap
	20 ns  --tspr
)
port map(
     d=>jed_sum_21,
     clk=>jed_node1,
     oe=>jed_oept_21,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>jed_node21,
     fb=>jed_fb_21
   );

Mcell_22:c22v10m
generic map(comb,
   ninv,
   xpin,
   	15 ns, --tpd
	15 ns, --tea
	15 ns, --ter
	8 ns, --tco
	10 ns, --ts
	0 ns, --th
	6 ns, --twh
	6 ns, --twl
	4 ns, --tcf
	15 ns, --taw
	12 ns, --tar
	20 ns, --tap
	20 ns  --tspr
)
port map(
     d=>jed_sum_22,
     clk=>jed_node1,
     oe=>jed_oept_22,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>s1,
     fb=>jed_fb_22
   );

Mcell_23:c22v10m
generic map(comb,
   ninv,
   xpin,
   	15 ns, --tpd
	15 ns, --tea
	15 ns, --ter
	8 ns, --tco
	10 ns, --ts
	0 ns, --th
	6 ns, --twh
	6 ns, --twl
	4 ns, --tcf
	15 ns, --taw
	12 ns, --tar
	20 ns, --tap
	20 ns  --tspr
)
port map(
     d=>jed_sum_23,
     clk=>jed_node1,
     oe=>jed_oept_23,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>s2,
     fb=>jed_fb_23
   );

jed_node25<=jed_sum_25;
jed_node26<=jed_sum_26;
jed_oept_14<=(one);

jed_sum_14<= (((jed_node3) and (jed_node4) and (jed_node5) and (jed_node8)
) or
((jed_node4) and (jed_node5) and (jed_node6) and (jed_node8)
) or
((jed_node3) and (jed_node5) and (jed_node7) and (jed_node8)
) or
((jed_node5) and (jed_node6) and (jed_node7) and (jed_node8)
) or
((jed_node3) and (jed_node4) and (jed_node7)) or
((jed_node4) and (jed_node6) and (jed_node7)) or
((jed_node3) and (jed_node6)));

jed_oept_15<=(one);

jed_sum_15<= (((jed_node4) and (jed_node5) and (jed_node8)) or
((jed_node5) and (jed_node7) and (jed_node8)) or
((jed_node4) and (jed_node7)));

jed_oept_16<=(one);

jed_sum_16<= (((jed_node5) and (jed_node8)));

jed_oept_18<=(one);

jed_sum_18<= (((jed_node3) and (jed_node4) and (jed_node5) and (jed_node6)
 and (jed_node8)) or
((jed_node3) and (jed_node5) and (jed_node6) and (jed_node7)
 and (jed_node8)) or
(not(jed_node3) and (jed_node4) and (jed_node5) and not(jed_node6)
 and (jed_node8)) or
(not(jed_node3) and (jed_node5) and not(jed_node6) and (jed_node7)
 and (jed_node8)) or
((jed_node3) and (jed_node4) and (jed_node6) and (jed_node7)
) or
((jed_node3) and not(jed_node6) and not(jed_node7) and not(jed_node8)
) or
((jed_node3) and not(jed_node5) and not(jed_node6) and not(jed_node7)
) or
((jed_node3) and not(jed_node4) and not(jed_node6) and not(jed_node8)
) or
((jed_node3) and not(jed_node4) and not(jed_node6) and not(jed_node7)
) or
((jed_node3) and not(jed_node4) and not(jed_node5) and not(jed_node6)
) or
(not(jed_node3) and (jed_node6) and not(jed_node7) and not(jed_node8)
) or
(not(jed_node3) and (jed_node4) and not(jed_node6) and (jed_node7)
) or
(not(jed_node3) and not(jed_node5) and (jed_node6) and not(jed_node7)
) or
(not(jed_node3) and not(jed_node4) and (jed_node6) and not(jed_node8)
) or
(not(jed_node3) and not(jed_node4) and (jed_node6) and not(jed_node7)
) or
(not(jed_node3) and not(jed_node4) and not(jed_node5)
 and (jed_node6)));

jed_oept_19<=(one);

jed_sum_19<= (((jed_node1) and (jed_node3) and (jed_node4) and (jed_node5)
 and (jed_node8)) or
((jed_node2) and (jed_node3) and (jed_node4) and (jed_node5)
 and (jed_node8)) or
((jed_node1) and (jed_node4) and (jed_node5) and (jed_node6)
 and (jed_node8)) or
((jed_node2) and (jed_node4) and (jed_node5) and (jed_node6)
 and (jed_node8)) or
((jed_node1) and (jed_node3) and (jed_node5) and (jed_node7)
 and (jed_node8)) or
((jed_node2) and (jed_node3) and (jed_node5) and (jed_node7)
 and (jed_node8)) or
((jed_node1) and (jed_node5) and (jed_node6) and (jed_node7)
 and (jed_node8)) or
((jed_node2) and (jed_node5) and (jed_node6) and (jed_node7)
 and (jed_node8)) or
((jed_node1) and (jed_node3) and (jed_node4) and (jed_node7)
) or
((jed_node2) and (jed_node3) and (jed_node4) and (jed_node7)
) or
((jed_node1) and (jed_node4) and (jed_node6) and (jed_node7)
) or
((jed_node2) and (jed_node4) and (jed_node6) and (jed_node7)
) or
((jed_node1) and (jed_node3) and (jed_node6)) or
((jed_node2) and (jed_node3) and (jed_node6)) or
((jed_node1) and (jed_node2)));

jed_oept_21<=(one);

jed_oept_22<=(one);

jed_sum_22<= (((jed_node5) and not(jed_node8)) or
(not(jed_node5) and (jed_node8)));

jed_oept_23<=(one);

jed_sum_23<= (((jed_node4) and (jed_node5) and (jed_node7) and (jed_node8)
) or
(not(jed_node4) and (jed_node5) and not(jed_node7) and (jed_node8)
) or
((jed_node4) and not(jed_node7) and not(jed_node8)) or
((jed_node4) and not(jed_node5) and not(jed_node7)) or
(not(jed_node4) and (jed_node7) and not(jed_node8)) or
(not(jed_node4) and not(jed_node5) and (jed_node7)));

end DSMB;
