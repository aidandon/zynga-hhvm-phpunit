<?hh // strict

/*
 * This file is part of the php-code-coverage package.
 *
 * (c) Sebastian Bergmann <sebastian@phpunit.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace SebastianBergmann\CodeCoverage;

/**
 * Interface for code coverage drivers.
 */
interface Driver {
  /**
   * @var int
   *
   * @see http://xdebug.org/docs/code_coverage
   */
  const LINE_EXECUTED = 1;

  /**
   * @var int
   *
   * @see http://xdebug.org/docs/code_coverage
   */
  const LINE_NOT_EXECUTED = -1;

  /**
   * @var int
   *
   * @see http://xdebug.org/docs/code_coverage
   */
  const LINE_NOT_EXECUTABLE = -2;

  /**
   * Start collection of code coverage information.
   *
   * @param bool $determineUnusedAndDead
   */
  public function start(bool $determineUnusedAndDead = true): void;

  /**
   * Stop collection of code coverage information.
   *
   * @return array
   */
  public function stop(): array<string, array<int, int>>;

}
