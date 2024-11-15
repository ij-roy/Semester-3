----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    17:18:25 10/15/2024 
-- Design Name: 
-- Module Name:    pipo - Behavioral 
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

entity pipo is
port(
clk:in std_logic;
enable:in std_logic;
reset:in std_logic;
data_in:in std_logic_vector(3 downto 0);
data_out:out std_logic_vector (3 downto 0)
);
end pipo;


architecture Behavioral of pipo is
	component d_ff 
	port ( d      : in std_logic;
			  clk    : in std_logic;
			  enable : in std_logic;
			  reset  : in std_logic;
			  q      : out std_logic);
	end component;

	begin
	step1: d_ff Port map (d=> data_in(0),clk=> clk,enable => enable,reset  => reset,q=>data_out(0));
	step2: d_ff Port map (d=> data_in(1),clk=> clk,enable => enable,reset  => reset,q=>data_out(1));
	step3: d_ff Port map (d=> data_in(2),clk=> clk,enable => enable,reset  => reset,q=>data_out(2));
	step4: d_ff Port map (d=> data_in(3),clk=> clk,enable => enable,reset  => reset,q=>data_out(3));

end Behavioral;