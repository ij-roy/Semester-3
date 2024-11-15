--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   18:48:52 10/15/2024
-- Design Name:   
-- Module Name:   /home/ise/Assignment3/ripple_counter_tb.vhd
-- Project Name:  Assignment3
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: ripple_counter
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
 
ENTITY ripple_counter_tb IS
END ripple_counter_tb;
 
ARCHITECTURE behavior OF ripple_counter_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT ripple_counter
    PORT(
         clk : IN  std_logic;
         enable : IN  std_logic;
         reset : IN  std_logic;
         count : OUT  std_logic_vector(3 downto 0)
        );
    END COMPONENT;
    
   --Inputs
   signal clk : std_logic := '0';
   signal enable : std_logic := '0';
   signal reset : std_logic := '0';

 	--Outputs
   signal count : std_logic_vector(3 downto 0);

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: ripple_counter PORT MAP (
          clk => clk,
          enable => enable,
          reset => reset,
          count => count
        );

   -- Clock process definitions
   clk_process :process
   begin
		while true loop
			clk <= '0';
			wait for clk_period/2;
			clk <= '1';
			wait for clk_period/2;
		end loop;
   end process;
 
   -- Stimulus process
   stim_proc: process
   begin		
		reset <= '1';  
		enable <= '0'; 
		wait for 20 ns;
		reset <= '0';  
		wait for 20 ns; 
		enable <= '1'; 
		wait for 50 ns;
		enable <= '0'; 
		wait for 20 ns; 
		enable <= '1'; 
		wait for 50 ns; 
		reset <= '1'; 
		wait for 20 ns; 
		reset <= '0'; 
		wait for 20 ns; 
		enable <= '1'; 
		wait for 50 ns;
	wait;
   end process;
END;