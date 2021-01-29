library ieee;
use ieee.std_logic_1164.all;

entity sum is

    port(x, y: in std_logic;
        s: out std_logic;
        a: out std_logic);

end sum;

architecture codigo of sum is
begin

    s<= (x xor y);
    a<= (x and y);
end codigo;