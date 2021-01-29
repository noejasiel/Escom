library ieee;
use ieee.std_logic_1164.all;

entity ff_KJT is
	Port (k,j,t, clk: in std_logic;
		
		q1, q2: out std_logic);
		attribute pin_numbers of ff_KJT: entity is 
		"clk:1 j:2 k:3 t:4 q1:23 q2:14 ";
end ff_KJT;

architecture arq_ff_KJT of ff_KJT is

signal a,b: std_logic;

begin 
	process (clk,k,j,t,a,b)
	begin
	if(clk' event and clk = '1')then
	
	if (t = '0') then
	a <= a;
	elsif(t ='1')then
	a <= not(a);
	end if;

	end if;

		end process;
		q2 <= a;
end arq_ff_KJT;
