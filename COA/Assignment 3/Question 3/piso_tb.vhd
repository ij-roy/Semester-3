--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   18:35:51 10/15/2024
-- Design Name:   
-- Module Name:   /home/ise/Assignment3/piso_tb.vhd
-- Project Name:  Assignment3
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: piso
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY piso_tb IS
END piso_tb;
 
ARCHITECTURE behavior OF piso_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT piso
    PORT(
         clk : IN  std_logic;
         reset : IN  std_logic;
         enable : IN  std_logic;
         mode : IN  std_logic;
         parallel_in : IN  std_logic_vector(3 downto 0);
         serial_in : IN  std_logic;
         serial_out : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal clk : std_logic := '0';
   signal reset : std_logic := '0';
   signal enable : std_logic := '0';
   signal mode : std_logic := '0';
   signal parallel_in : std_logic_vector(3 downto 0) := (others => '0');
   signal serial_in : std_logic := '0';

 	--Outputs
   signal serial_out : std_logic;

   -- Clock period definitions
   constant clk_period : time := 100 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: piso PORT MAP (
          clk => clk,
          reset => reset,
          enable => enable,
          mode => mode,
          parallel_in => parallel_in,
          serial_in => serial_in,
          serial_out => serial_out
        );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin	
		reset <= '1';
		wait for 100 ns; 
		reset <= '0';
		wait for 100 ns;
		enable <= '1';
		mode <= '0'; 
		parallel_in <= "0101"; 
		wait for 100 ns;
		mode <= '1';  
		serial_in <= '1';  
		wait for 100 ns;
		wait for 100 ns;  
		serial_in <= '0';  
		wait for 100 ns;
		serial_in <= '1'; 
		wait for 100 ns;
		serial_in <= '1';  
		wait for 100 ns;
	wait;
   end process;

END;