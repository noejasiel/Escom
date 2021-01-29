library ieee;
use ieee.std_logic_1164.all;

entity res is

    port(x, y: in std_logic;
        s: out std_logic;
        a: out std_logic);

end res;

architecture codigo of res is
begin

    s<= (x xor y);
    a<= ((not x) and y);
end codigo;
