library  IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.std_logic_unsigned.all;
entity SUMA is 

	port(c0, a1, a2, a3, a4, b1, b2, b3, b4: in std_logic;
	s1, s2, s3, s4: out std_logic;
	c1, c2, c3: out std_logic);

end SUMA;

architecture codigo of SUMA is 
begin


c0 <= '0';

	s1 <= ((a1 xor b1)xor c0) ;
	c1 <= ((a1 and c0) or (a1 and b1) or (b1 and c0));

	s2 <= ((a2 xor b2)xor c1) ;
	c2 <= ((a2 and c1) or (a2 and b2) or (b2 and c1));

	s3 <= ((a3 xor b3)xor c2) ;
	c3 <= ((a3 and c2) or (a3 and b3) or (b3 and c2));

	s4 <= ((a4 xor b4)xor c3) ;
--	c4 <= ((a4 and c3) or (a4 and b4) or (b4 and c3));




end codigo;
