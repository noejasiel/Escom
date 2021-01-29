
--  CYPRESS NOVA XVL Structural Architecture

--  JED2VHD Reverse Assembler - 6.3 IR 35


--    VHDL File: compuertas.vhd

--    Date: Sun Sep 15 04:20:10 2019

--  Disassembly from Jedec file for: c22v10

--  Device Ordercode is: PALC22V10D-25PC
library ieee;
use ieee.std_logic_1164.all;

library primitive;
use primitive.primitive.all;


-- Beginning Test Bench Header

ENTITY compuertas IS
    PORT (
	                 sel :    in std_logic_vector (2 downto 0) ;
	                   a :    in std_logic ;
	                   b :    in std_logic ;
	                   c :    in std_logic ;
	              salida : inout std_logic
    );
END compuertas;

-- End of Test Bench Header

ARCHITECTURE DSMB of compuertas is

	signal jed_node1	: std_logic:='0' ; -- sel(2)
	signal jed_node2	: std_logic:='0' ; -- sel(1)
	signal jed_node3	: std_logic:='0' ; -- sel(0)
	signal jed_node4	: std_logic:='0' ; -- c
	signal jed_node5	: std_logic:='0' ; -- b
	signal jed_node6	: std_logic:='0' ; -- a
	signal jed_node7	: std_logic:='0' ;
	signal jed_node8	: std_logic:='0' ;
	signal jed_node9	: std_logic:='0' ;
	signal jed_node10	: std_logic:='0' ;
	signal jed_node11	: std_logic:='0' ;
	signal jed_node12	: std_logic:='0' ;
	signal jed_node13	: std_logic:='0' ;
	signal jed_node14	: std_logic:='0' ;
	signal jed_node15	: std_logic:='0' ;
	signal jed_node17	: std_logic:='0' ;
	signal jed_node18	: std_logic:='0' ;
	signal jed_node19	: std_logic:='0' ;
	signal jed_node20	: std_logic:='0' ;
	signal jed_node21	: std_logic:='0' ;
	signal jed_node22	: std_logic:='0' ;
	signal jed_node23	: std_logic:='0' ;
	signal jed_node24	: std_logic:='0' ;

	for all: c22v10m use entity primitive.c22v10m (sim);

SIGNAL  one:std_logic:='1';
SIGNAL  zero:std_logic:='0';
SIGNAL  jed_oept_1:std_logic:='0';
--Attribute PIN_NUMBERS of sel(2):SIGNAL is "0001";

SIGNAL  jed_oept_2:std_logic:='0';
--Attribute PIN_NUMBERS of sel(1):SIGNAL is "0002";

SIGNAL  jed_oept_3:std_logic:='0';
--Attribute PIN_NUMBERS of sel(0):SIGNAL is "0003";

SIGNAL  jed_oept_4:std_logic:='0';
--Attribute PIN_NUMBERS of c:SIGNAL is "0004";

SIGNAL  jed_oept_5:std_logic:='0';
--Attribute PIN_NUMBERS of b:SIGNAL is "0005";

SIGNAL  jed_oept_6:std_logic:='0';
--Attribute PIN_NUMBERS of a:SIGNAL is "0006";

SIGNAL  jed_oept_16:std_logic:='0';
SIGNAL  jed_sum_16,jed_fb_16:std_logic:='0';
--Attribute PIN_NUMBERS of salida:SIGNAL is "0016";

SIGNAL  jed_oept_25:std_logic:='0';
SIGNAL  jed_node25,jed_sum_25:std_logic:='0';
SIGNAL  jed_oept_26:std_logic:='0';
SIGNAL  jed_node26,jed_sum_26:std_logic:='0';

BEGIN
jed_node1 <= sel(2) ;
jed_node2 <= sel(1) ;
jed_node3 <= sel(0) ;
jed_node4 <= c ;
jed_node5 <= b ;
jed_node6 <= a ;
Mcell_16:c22v10m
generic map(comb,
   ninv,
   xpin,
   	25 ns, --tpd
	25 ns, --tea
	25 ns, --ter
	15 ns, --tco
	18 ns, --ts
	0 ns, --th
	14 ns, --twh
	14 ns, --twl
	13 ns, --tcf
	25 ns, --taw
	25 ns, --tar
	25 ns, --tap
	25 ns  --tspr
)
port map(
     d=>jed_sum_16,
     clk=>jed_node1,
     oe=>jed_oept_16,
     ss=>jed_sum_26,
     ar=>jed_sum_25,
     y=>salida,
     fb=>jed_fb_16
   );

jed_node25<=jed_sum_25;
jed_node26<=jed_sum_26;
jed_oept_16<=(one);

jed_sum_16<= (((jed_node1) and not(jed_node2) and (jed_node3) and (jed_node4)
 and not(jed_node5) and not(jed_node6)) or
((jed_node1) and not(jed_node2) and (jed_node3) and not(jed_node4)
 and (jed_node5) and not(jed_node6)) or
((jed_node1) and not(jed_node2) and (jed_node3) and not(jed_node4)
 and not(jed_node5) and (jed_node6)) or
((jed_node2) and not(jed_node3) and (jed_node4) and (jed_node5)
 and not(jed_node6)) or
((jed_node2) and not(jed_node3) and (jed_node4) and not(jed_node5)
 and (jed_node6)) or
((jed_node2) and not(jed_node3) and not(jed_node4) and (jed_node5)
 and (jed_node6)) or
((jed_node1) and not(jed_node3) and not(jed_node4) and not(jed_node5)
 and not(jed_node6)) or
(not(jed_node2) and (jed_node3) and (jed_node4) and (jed_node5)
 and (jed_node6)) or
(not(jed_node1) and (jed_node2) and (jed_node5) and not(jed_node6)
) or
(not(jed_node1) and (jed_node2) and (jed_node4) and not(jed_node5)
) or
(not(jed_node1) and (jed_node2) and (jed_node3) and not(jed_node4)
) or
(not(jed_node1) and (jed_node2) and not(jed_node3) and (jed_node6)
));

end DSMB;
