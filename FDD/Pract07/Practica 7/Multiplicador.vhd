library ieee;
library ieee;
use ieee.std_logic_1164.all;
entity arq_multi is
	port(A, B: in std_logic_vector(1 downto 0);
		s: out std_logic_vector(3 downto 0));
end arq_multi;

architecture multiplicacion of arq_multi is
begin
s(0) <= A(1) and B(1);
s(1) <= ((A(1) and B(0)) xor (A(0) and B(1)));
s(2) <= not(A(1) and B(1)) and (A(0) and B(0));
s(3) <= (A(1) and B(1)) and (A(0) and B(0));

end  multiplicacion;