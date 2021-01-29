
--  CYPRESS NOVA XVL Structural Architecture

--  JED2VHD Reverse Assembler - 6.3 IR 35


--    VHDL File: sumador.vhd

--    Date: Wed Oct 09 10:33:35 2019

--  Disassembly from Jedec file for: c22v10

--  Device Ordercode is: PALCE22V10-15PC
library ieee;
use ieee.std_logic_1164.all;

library primitive;
use primitive.primitive.all;


-- Beginning Test Bench Header

ENTITY sum IS
    PORT (
	                sump :    in std_logic_vector (3 downto 0) ;
	                sumg :    in std_logic_vector (3 downto 0) ;
	              salida : inout std_logic_vector (4 downto 0)
    );
END sum;

-- End of Test Bench Header

ARCHITECTURE DSMB of sum is

	signal jed_node1	: std_logic:='0' ; -- sump(3)
	signal jed_node2	: std_logic:='0' ; -- sump(2)
	signal jed_node3	: std_logic:='0' ; -- sump(1)
	signal jed_node4	: std_logic:='0' ; -- sump(0)
	signal jed_node5	: std_logic:='0' ; -- sumg(3)
	signal jed_node6	: std_logic:='0' ; -- sumg(2)
	signal jed_node7	: std_logic:='0' ; -- sumg(1)
	signal jed_node8	: std_logic:='0' ; -- sumg(0)
	signal jed_node9	: std_logic:='0' ;
	signal jed_node10	: std_logic:='0' ;
	signal jed_node11	: std_logic:='0' ;
	signal jed_node12	: std_logic:='0' ;
	signal jed_node13	: std_logic:='0' ;
	signal jed_node15	: std_logic:='0' ;
	signal jed_node18	: std_logic:='0' ;
	signal jed_node19	: std_logic:='0' ;
	signal jed_node20	: std_logic:='0' ;
	signal jed_node22	: std_logic:='0' ;
	signal jed_node24	: std_logic:='0' ;

	for all: c22v10m use entity primitive.c22v10m (sim);

SIGNAL  one:std_logic:='1';
SIGNAL  zero:std_logic:='0';
SIGNAL  jed_oept_1:std_logic:='0';
--Attribute PIN_NUMBERS of sump(3):SIGNAL is "0001";

SIGNAL  jed_oept_2:std_logic:='0';
--Attribute PIN_NUMBERS of sump(2):SIGNAL is "0002";

SIGNAL  jed_oept_3:std_logic:='0';
--Attribute PIN_NUMBERS of sump(1):SIGNAL is "0003";

SIGNAL  jed_oept_4:std_logic:='0';
--Attribute PIN_NUMBERS of sump(0):SIGNAL is "0004";

SIGNAL  jed_oept_5:std_logic:='0';
--Attribute PIN_NUMBERS of sumg(3):SIGNAL is "0005";

SIGNAL  jed_oept_6:std_logic:='0';
--Attribute PIN_NUMBERS of sumg(2):SIGNAL is "0006";

SIGNAL  jed_oept_7:std_logic:='0';
--Attribute PIN_NUMBERS of sumg(1):SIGNAL is "0007";

SIGNAL  jed_oept_8:std_logic:='0';
--Attribute PIN_NUMBERS of sumg(0):SIGNAL is "0008";

SIGNAL  jed_oept_14:std_logic:='0';
SIGNAL  jed_sum_14,jed_fb_14:std_logic:='0';
--Attribute PIN_NUMBERS of salida(1):SIGNAL is "0014";

SIGNAL  jed_oept_15:std_logic:='0';
SIGNAL \MODULE_2:g1:a0:g0:g2:u0:ga:t1:ga0(1):gas:u1\:std_logic:='0';
SIGNAL  jed_sum_15,jed_fb_15:std_logic:='0';
--Attribute PIN_NUMBERS of jed_node15:SIGNAL is "0015";

SIGNAL  jed_oept_16:std_logic:='0';
SIGNAL  jed_sum_16,jed_fb_16:std_logic:='0';
--Attribute PIN_NUMBERS of salida(3):SIGNAL is "0016";

SIGNAL  jed_oept_17:std_logic:='0';
SIGNAL  jed_sum_17,jed_fb_17:std_logic:='0';
--Attribute PIN_NUMBERS of salida(0):SIGNAL is "0017";

SIGNAL  jed_oept_20:std_logic:='0';
SIGNAL \MODULE_2:g1:a0:g0:g2:u0:ga:t1:ga0(1):gas:u2\:std_logic:='0';
SIGNAL  jed_sum_20,jed_fb_20:std_logic:='0';
--Attribute PIN_NUMBERS of jed_node20:SIGNAL is "0020";

SIGNAL  jed_oept_21:std_logic:='0';
SIGNAL  jed_sum_21,jed_fb_21:std_logic:='0';
--Attribute PIN_NUMBERS of salida(4):SIGNAL is "0021";

SIGNAL  jed_oept_22:std_logic:='0';
SIGNAL \MODULE_2:g1:a0:g0:g2:u0:ga:g1:ua0\:std_logic:='0';
SIGNAL  jed_sum_22,jed_fb_22:std_logic:='0';
--Attribute PIN_NUMBERS of jed_node22:SIGNAL is "0022";

SIGNAL  jed_oept_23:std_logic:='0';
SIGNAL  jed_sum_23,jed_fb_23:std_logic:='0';
--Attribute PIN_NUMBERS of salida(2):SIGNAL is "0023";

SIGNAL  jed_oept_25:std_logic:='0';
SIGNAL  jed_node25,jed_sum_25:std_logic:='0';
SIGNAL  jed_oept_26:std_logic:='0';
SIGNAL  jed_node26,jed_sum_26:std_logic:='0';

BEGIN
jed_node1 <= sump(3) ;
jed_node2 <= sump(2) ;
jed_node3 <= sump(1) ;
jed_node4 <= sump(0) ;
jed_node5 <= sumg(3) ;
jed_node6 <= sumg(2) ;
jed_node7 <= sumg(1) ;
jed_node8 <= sumg(0) ;
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
     y=>salida(1),
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
     y=>jed_node15,
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
     y=>salida(3),
     fb=>jed_fb_16
   );

Mcell_17:c22v10m
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
     d=>jed_sum_17,
     clk=>jed_node1,
     oe=>jed_oept_17,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>salida(0),
     fb=>jed_fb_17
   );

Mcell_20:c22v10m
generic map(comb,
   invt,
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
     d=>jed_sum_20,
     clk=>jed_node1,
     oe=>jed_oept_20,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>jed_node20,
     fb=>jed_fb_20
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
     y=>salida(4),
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
     y=>jed_node22,
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
     y=>salida(2),
     fb=>jed_fb_23
   );

\MODULE_2:g1:a0:g0:g2:u0:ga:t1:ga0(1):gas:u1\ <= jed_fb_15;
\MODULE_2:g1:a0:g0:g2:u0:ga:t1:ga0(1):gas:u2\ <= jed_fb_20;
\MODULE_2:g1:a0:g0:g2:u0:ga:g1:ua0\ <= jed_fb_22;
jed_node25<=jed_sum_25;
jed_node26<=jed_sum_26;
jed_oept_14<=(one);

jed_sum_14<= (((jed_node3) and (jed_node4) and (jed_node7) and (jed_node8)
) or
(not(jed_node3) and (jed_node4) and not(jed_node7) and (jed_node8)
) or
((jed_node3) and not(jed_node7) and not(jed_node8)) or
((jed_node3) and not(jed_node4) and not(jed_node7)) or
(not(jed_node3) and (jed_node7) and not(jed_node8)) or
(not(jed_node3) and not(jed_node4) and (jed_node7)));

jed_oept_15<=(one);

jed_sum_15<= (((jed_node1) and (jed_node2) and (jed_node6)) or
((jed_node2) and (jed_node5) and (jed_node6)) or
((jed_node1) and (jed_node5)));

jed_oept_16<=(one);

jed_sum_16<= (((jed_node1) and (jed_node2) and (jed_node5) and (jed_node6)
) or
((jed_node1) and (jed_node2) and (jed_fb_22) and (jed_node5)
) or
((jed_node1) and (jed_fb_22) and (jed_node5) and (jed_node6)
) or
((jed_node1) and not(jed_fb_22) and not(jed_node5) and not(jed_node6)
) or
((jed_node1) and not(jed_node2) and not(jed_fb_22) and not(jed_node5)
) or
((jed_node1) and not(jed_node2) and not(jed_node5) and not(jed_node6)
) or
(not(jed_node1) and not(jed_fb_22) and (jed_node5) and not(jed_node6)
) or
(not(jed_node1) and (jed_node2) and not(jed_node5) and (jed_node6)
) or
(not(jed_node1) and (jed_node2) and (jed_fb_22) and not(jed_node5)
) or
(not(jed_node1) and (jed_fb_22) and not(jed_node5) and (jed_node6)
) or
(not(jed_node1) and not(jed_node2) and not(jed_fb_22)
 and (jed_node5)) or
(not(jed_node1) and not(jed_node2) and (jed_node5) and not(jed_node6)
));

jed_oept_17<=(one);

jed_sum_17<= (((jed_node4) and not(jed_node8)) or
(not(jed_node4) and (jed_node8)));

jed_oept_20<=(one);

jed_sum_20<= ((not(jed_node2) and not(jed_node6)) or
(not(jed_node1) and not(jed_node5)));

jed_oept_21<=(one);

jed_sum_21<= (((jed_fb_22) and (jed_fb_20)) or
((jed_fb_15)));

jed_oept_22<=(one);

jed_sum_22<= (((jed_node3) and (jed_node4) and (jed_node8)) or
((jed_node4) and (jed_node7) and (jed_node8)) or
((jed_node3) and (jed_node7)));

jed_oept_23<=(one);

jed_sum_23<= (((jed_node2) and (jed_fb_22) and (jed_node6)) or
((jed_node2) and not(jed_fb_22) and not(jed_node6)) or
(not(jed_node2) and not(jed_fb_22) and (jed_node6)) or
(not(jed_node2) and (jed_fb_22) and not(jed_node6)));

end DSMB;
