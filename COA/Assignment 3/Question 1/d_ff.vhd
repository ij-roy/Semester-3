----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    17:21:24 10/15/2024 
-- Design Name: 
-- Module Name:    d_ff - arch_diff
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

entity d_ff is
port ( d      : in std_logic;
        clk    : in std_logic;
        enable : in std_logic;
        reset  : in std_logic;
        q      : out std_logic);
end d_ff;
architecture arch_dff of d_ff is
begin
process (clk,reset)
begin
if reset ='1' then
   q <='0';
	elsif rising_edge(clk) then
	if enable ='1' then
	q <= d;

end if;
end if;
end process;
end arch_dff;