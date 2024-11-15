--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   18:19:38 10/15/2024
-- Design Name:   
-- Module Name:   /home/ise/Assignment3/siso_tb.vhd
-- Project Name:  Assignment3
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: siso
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
 
ENTITY siso_tb IS
END siso_tb;
 
ARCHITECTURE behavior OF siso_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT siso
    PORT(
         clk : IN  std_logic;
         enable : IN  std_logic;
         reset : IN  std_logic;
         serial_in : IN  std_logic;
         serial_out : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal clk : std_logic := '0';
   signal enable : std_logic := '0';
   signal reset : std_logic := '0';
   signal serial_in : std_logic := '0';

 	--Outputs
   signal serial_out : std_logic;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: siso PORT MAP (
          clk => clk,
          enable => enable,
          reset => reset,
          serial_in => serial_in,
          serial_out => serial_out
        );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for 50 ns;
		clk <= '1';
		wait for 50 ns;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
		reset <= '1';
		wait for 10 ns;
		
		reset <= '0';
		enable <= '1';
		
		serial_in <= '1'; wait for 10 ns;
		serial_in <= '0'; wait for 10 ns;
		serial_in <= '0'; wait for 10 ns;
		serial_in <= '1'; wait for 10 ns;
		enable <= '0';
		
		wait for 200 ns;
		reset <= '1';
		wait for 100 ns;
		reset <= '0';
		
      wait;
   end process;

END;