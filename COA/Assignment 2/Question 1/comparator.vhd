----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    19:32:16 09/22/2024 
-- Design Name: 
-- Module Name:    comparator - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity comparator is
PORT(
A,B:IN STD_LOGIC_VECTOR(3 DOWNTO 0);
g,l,e: out std_logic);
end comparator;

architecture Behavioral of comparator is
signal s:std_logic_vector (3 downto 0);
begin
s(0)<=A(0) XNOR B(0);
s(1)<=A(1) XNOR B(1);
s(2)<=A(2) xNor B(2);
s(3)<=A(3) XNOR B(3);
g<=(A(3) AND NOT (B(3))) OR (s(3) and (A(2) AND (NOT B(2)))) OR(s(3) and  s(2) and (A(1) AND (NOT (B(1))))) OR (s(3) and s(2) and s(1) and (A(0) AND (NOT B(0))));
l<=(NOT(A(3)) AND B(3)) OR (s(3) and (NOT(A(2)) AND B(2))) OR(s(3) and  s(2) and (NOT (A(1)) AND  (B(1)))) OR (s(3) and s(2) and s(1) and (NOT(A(0)) AND  B(0)));
e<=(s(0) and s(1) and s(2) and s(3));
end Behavioral;