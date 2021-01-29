library ieee;
use ieee.std_logic_1164.all;

entity ff_rsd is
	Port (r,s,d, clk: in std_logic;
		q1, q2: out std_logic);
end ff_rsd;

architecture arq_ff_rsd of ff_rsd is
begin 
	process (clk,r,s,d)
	begin 
	if(clk' event and clk = '1')then
	q2 <= d;
	if(r ='0' and s='0')then
	q1 <= q1;
	elsif (r ='1' and s='0') then
	q1 <= '0';
	elsif (r ='0' and s ='1') then 
	q1 <= '1';

	else q1 <= not q1;
	end if;

	end if;

		end process;
end arq_ff_rsd;